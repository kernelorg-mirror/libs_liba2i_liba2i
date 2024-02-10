# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CPPLINT_INCLUDED
MAKEFILE_LINT_C_CPPLINT_INCLUDED := 1


include $(MAKEFILEDIR)/build/deps.mk
include $(MAKEFILEDIR)/configure/cpplint.mk
include $(MAKEFILEDIR)/cmd.mk


_TU_h_cpl  := $(addsuffix .lint-c.cpplint.touch,$(_TU_h))
_TU_c_cpl  := $(addsuffix .lint-c.cpplint.touch,$(_TU_c))
_TU_cpl    := $(_TU_h_cpl) $(_TU_c_cpl)


$(_TU_cpl): %.lint-c.cpplint.touch: % $(CPPLINT_CONF) $(MK) | %.d $$(@D)/
	$(info	LINT (cpplint)		$@)
	$(CPPLINT) $(CPPLINTFLAGS) $< >/dev/null
	$(TOUCH) $@


.PHONY: lint-c-cpplint
lint-c-cpplint: $(_TU_cpl)
	@:


endif  # include guard
