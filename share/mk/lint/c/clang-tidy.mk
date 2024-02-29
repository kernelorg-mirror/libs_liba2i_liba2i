# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CLANG_TIDY_INCLUDED
MAKEFILE_LINT_C_CLANG_TIDY_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/clang.mk
include $(MAKEFILEDIR)/configure/build-depends/clang-tidy.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/sed.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_ct := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.clang-tidy.touch,$(TU_h))
_TU_c_ct := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.clang-tidy.touch,$(TU_c))
_TU_ct   := $(_TU_h_ct) $(_TU_c_ct)


$(_TU_h_ct): $(builddir)/%.lint-c.clang-tidy.touch: $(INCLUDEDIR)/%
$(_TU_c_ct): $(builddir)/%.lint-c.clang-tidy.touch: $(SRCDIR)/%
$(_TU_ct): %.lint-c.clang-tidy.touch: $(CLANG_TIDY_CONF) $(MK) | %.d $$(@D)/


$(_TU_ct):
	$(info	$(INFO_)CLANG_TIDY	$@)
	$(CLANG_TIDY) $(CLANG_TIDYFLAGS) $< -- $(CPPFLAGS) $(CLANGFLAGS) 2>&1 \
	| $(SED) '/generated\.$$/d' >&2
	$(TOUCH) $@


.PHONY: lint-c-clang-tidy
lint-c-clang-tidy: $(_TU_ct);


endif  # include guard
