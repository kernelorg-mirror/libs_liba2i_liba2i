# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CPPCHECK_INCLUDED
MAKEFILE_LINT_C_CPPCHECK_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/build-depends/cppcheck/cppcheck.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/tu.mk


_LINT_c_TU_h_cppcheck := $(patsubst $(INCLUDEDIR)/%, $(builddir)/%.lint-c.cppcheck.touch, $(TU_h))
_LINT_c_TU_c_cppcheck := $(patsubst $(SRCLIBDIR)/%,  $(builddir)/%.lint-c.cppcheck.touch, $(TU_c))
_LINT_c_TU_cppcheck   := $(_LINT_c_TU_h_cppcheck) $(_LINT_c_TU_c_cppcheck)
_LINT_c_LIB_cppcheck  := $(builddir)/$(libname).lint-c.cppcheck.touch
_LINT_c_EX_cppcheck   := $(patsubst %, %.lint-c.cppcheck.touch, $(_EX_TU_src))
_LINT_c_cppcheck      := \
	$(_LINT_c_TU_cppcheck) \
	$(_LINT_c_LIB_cppcheck) \
	$(_LINT_c_EX_cppcheck)


$(_LINT_c_TU_h_cppcheck): $(builddir)/%.lint-c.cppcheck.touch: $(INCLUDEDIR)/%
$(_LINT_c_TU_c_cppcheck): $(builddir)/%.lint-c.cppcheck.touch: $(SRCLIBDIR)/%
$(_LINT_c_TU_cppcheck): %.lint-c.cppcheck.touch: | %.d
$(_LINT_c_LIB_cppcheck): $(TU_c) $(TU_h)
$(_LINT_c_EX_cppcheck): %.lint-c.cppcheck.touch: %
$(_LINT_c_cppcheck): $(CPPCHECK_SUPPRESS) $(MK) | $$(@D)/


$(_LINT_c_TU_cppcheck):
	$(info	$(INFO_)CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS_) -I $(INCLUDEDIR) -I $(srcdir) $<
	$(TOUCH) $@

$(_LINT_c_LIB_cppcheck):
	$(info	$(INFO_)CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS_) -I $(INCLUDEDIR) -I $(srcdir) $(TU_c) $(TU_h)
	$(TOUCH) $@

$(_LINT_c_EX_cppcheck):
	$(info	$(INFO_)CPPCHECK	$@)
	$(CPPCHECK) $(CPPCHECKFLAGS_) $<
	$(TOUCH) $@


.PHONY: lint-c-cppcheck
lint-c-cppcheck: $(_LINT_c_cppcheck);


endif  # include guard
