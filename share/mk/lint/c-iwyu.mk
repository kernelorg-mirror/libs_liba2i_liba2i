# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_IWYU_INCLUDED
MAKEFILE_LINT_C_IWYU_INCLUDED := 1


include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/cpp.mk
include $(MAKEFILEDIR)/configure/iwyu.mk
include $(MAKEFILEDIR)/configure/sed.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_iwyu := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.iwyu.touch,$(TU_h))
_TU_c_iwyu := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.iwyu.touch,$(TU_c))
_TU_iwyu   := $(_TU_h_iwyu) $(_TU_c_iwyu)


$(_TU_iwyu): %.lint-c.iwyu.touch: $(MK) | %.d $$(@D)/


$(_TU_h_iwyu): $(builddir)/%.lint-c.iwyu.touch: $(INCLUDEDIR)/%
	$(info	IWYU		$@)
	$(IWYU) $(IWYUFLAGS) $(CPPFLAGS) $(CLANGCFLAGS) $< 2>&1 \
	| $(TAC) \
	| $(SED) '/correct/{N;d}' \
	| $(TAC) >&2
	$(TOUCH) $@

$(_TU_c_iwyu): $(builddir)/%.lint-c.iwyu.touch: $(SRCDIR)/%
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
