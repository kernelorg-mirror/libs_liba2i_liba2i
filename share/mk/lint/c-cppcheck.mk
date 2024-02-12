# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CPPCHECK_INCLUDED
MAKEFILE_LINT_C_CPPCHECK_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/cppcheck.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_cck := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.cppcheck.touch,$(TU_h))
_TU_c_cck := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.cppcheck.touch,$(TU_c))
_TU_cck   := $(_TU_h_cck) $(_TU_c_cck)


_LIB_cck := $(builddir)/$(libname).lint-c.cppcheck.touch


$(_TU_cck): %.lint-c.cppcheck.touch: $(CPPCHECK_CONF) $(MK) | %.d $$(@D)/


$(_TU_h_cck): $(builddir)/%.lint-c.cppcheck.touch: $(INCLUDEDIR)/%
	$(info	CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $<
	$(TOUCH) $@

$(_TU_c_cck): $(builddir)/%.lint-c.cppcheck.touch: $(SRCDIR)/%
	$(info	CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $<
	$(TOUCH) $@

$(_LIB_cck): $(builddir)/%.lint-c.cppcheck.touch: $(TU_c) $(TU_h) $(CPPCHECK_CONF) $(MK) | $$(@D)/
	$(info	CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $(TU_c) $(TU_h)
	$(TOUCH) $@


.PHONY: lint-c-cppcheck
lint-c-cppcheck: $(_TU_cck) $(_LIB_cck)
	@:


endif  # include guard
