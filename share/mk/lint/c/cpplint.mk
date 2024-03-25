# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CPPLINT_INCLUDED
MAKEFILE_LINT_C_CPPLINT_INCLUDED := 1


include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/build-depends/cpplint/cpplint.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/tu.mk


_LINT_c_TU_h_cpplint := $(patsubst $(INCLUDEDIR)/%, $(builddir)/%.lint-c.cpplint.touch, $(TU_h))
_LINT_c_TU_c_cpplint := $(patsubst $(LIBSRCDIR)/%,  $(builddir)/%.lint-c.cpplint.touch, $(TU_c))
_LINT_c_TU_cpplint   := $(_LINT_c_TU_h_cpplint) $(_LINT_c_TU_c_cpplint)
_LINT_c_EX_cpplint   := $(patsubst %, %.lint-c.cpplint.touch, $(_EX_TU_src))
_LINT_c_cpplint      := $(_LINT_c_TU_cpplint) $(_LINT_c_EX_cpplint)


$(_LINT_c_TU_h_cpplint): $(builddir)/%.lint-c.cpplint.touch: $(INCLUDEDIR)/%
$(_LINT_c_TU_c_cpplint): $(builddir)/%.lint-c.cpplint.touch: $(LIBSRCDIR)/%
$(_LINT_c_TU_cpplint): %.lint-c.cpplint.touch: | %.d
$(_LINT_c_EX_cpplint): %.lint-c.cpplint.touch: %
$(_LINT_c_cpplint): $(CPPLINT_CONF) $(MK) | $$(@D)/


$(_LINT_c_cpplint):
	$(info	$(INFO_)CPPLINT		$@)
	$(CPPLINT) $(CPPLINTFLAGS) $< >/dev/null
	$(TOUCH) $@


.PHONY: lint-c-cpplint
lint-c-cpplint: $(_LINT_c_cpplint);


endif  # include guard
