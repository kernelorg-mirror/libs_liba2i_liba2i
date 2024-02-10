# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_IWYU_INCLUDED
MAKEFILE_LINT_C_IWYU_INCLUDED := 1


include $(MAKEFILEDIR)/build/dev-src.mk
include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/cpp.mk
include $(MAKEFILEDIR)/configure/iwyu.mk
include $(MAKEFILEDIR)/configure/sed.mk


_TU_h_iwyu := $(addsuffix .lint-c.iwyu.touch,$(_TU_h))
_TU_c_iwyu := $(addsuffix .lint-c.iwyu.touch,$(_TU_c))
_TU_iwyu   := $(_TU_h_iwyu) $(_TU_c_iwyu)


$(_TU_iwyu): %.lint-c.iwyu.touch: % $(MK) | %.d $$(@D)/
	$(info	IWYU		$@)
	$(IWYU) $(IWYUFLAGS) $(CPPFLAGS) $(CLANGCFLAGS) $< 2>&1 \
	| $(TAC) \
	| $(SED) '/correct/{N;d}' \
	| $(TAC) >&2
	$(TOUCH) $@


.PHONY: lint-c-iwyu
lint-c-iwyu: $(_TU_iwyu)
	@:


endif  # include guard
