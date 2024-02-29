# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CPPLINT_INCLUDED
MAKEFILE_LINT_C_CPPLINT_INCLUDED := 1


include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/cpplint.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_cpl := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.cpplint.touch,$(TU_h))
_TU_c_cpl := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.cpplint.touch,$(TU_c))
_TU_cpl   := $(_TU_h_cpl) $(_TU_c_cpl)


$(_TU_h_cpl): $(builddir)/%.lint-c.cpplint.touch: $(INCLUDEDIR)/%
$(_TU_c_cpl): $(builddir)/%.lint-c.cpplint.touch: $(SRCDIR)/%
$(_TU_cpl): %.lint-c.cpplint.touch: $(CPPLINT_CONF) $(MK) | %.d $$(@D)/


$(_TU_cpl):
	$(info	$(INFO_)CPPLINT		$@)
	$(CPPLINT) $(CPPLINTFLAGS) $< >/dev/null
	$(TOUCH) $@


.PHONY: lint-c-cpplint
lint-c-cpplint: $(_TU_cpl);


endif  # include guard
