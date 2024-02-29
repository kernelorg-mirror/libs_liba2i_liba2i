# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CPPCHECK_INCLUDED
MAKEFILE_LINT_C_CPPCHECK_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/cppcheck.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_cck := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.cppcheck.touch,$(TU_h))
_TU_c_cck := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.cppcheck.touch,$(TU_c))
_TU_cck   := $(_TU_h_cck) $(_TU_c_cck)
_LIB_cck  := $(builddir)/$(libname).lint-c.cppcheck.touch


$(_TU_h_cck): $(builddir)/%.lint-c.cppcheck.touch: $(INCLUDEDIR)/%
$(_TU_c_cck): $(builddir)/%.lint-c.cppcheck.touch: $(SRCDIR)/%
$(_TU_cck): %.lint-c.cppcheck.touch: $(CPPCHECK_SUPPRESS) $(MK) | %.d $$(@D)/
$(_LIB_cck): $(TU_c) $(TU_h) $(CPPCHECK_SUPPRESS) $(MK) | $$(@D)/


$(_TU_cck):
	$(info	$(INFO_)CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $<
	$(TOUCH) $@

$(_LIB_cck):
	$(info	$(INFO_)CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $(TU_c) $(TU_h)
	$(TOUCH) $@


.PHONY: lint-c-cppcheck
lint-c-cppcheck: $(_TU_cck) $(_LIB_cck);


endif  # include guard
