# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CPPCHECK_INCLUDED
MAKEFILE_LINT_C_CPPCHECK_INCLUDED := 1


include $(MAKEFILEDIR)/build/dev-src.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/configure/cppcheck.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_cck  := $(addsuffix .lint-c.cppcheck.touch,$(_TU_h))
_TU_c_cck  := $(addsuffix .lint-c.cppcheck.touch,$(_TU_c))
_TU_cck    := $(_TU_h_cck) $(_TU_c_cck)


_LIB_cck := $(builddir)/$(libname).lint-c.cppcheck.touch


$(_TU_cck): %.lint-c.cppcheck.touch: % $(CPPCHECK_CONF) $(MK) | %.d $$(@D)/
	$(info	LINT (cppcheck)		$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $<
	$(TOUCH) $@

$(_LIB_cck): %.lint-c.cppcheck.touch: $(_TU_c) $(_TU_h) $(CPPCHECK_CONF) $(MK) | $$(@D)/
	$(info	LINT (cppcheck)		$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $(_TU_c) $(_TU_h)
	$(TOUCH) $@


.PHONY: lint-c-cppcheck
lint-c-cppcheck: $(_TU_cck) $(_LIB_cck)
	@:


endif  # include guard
