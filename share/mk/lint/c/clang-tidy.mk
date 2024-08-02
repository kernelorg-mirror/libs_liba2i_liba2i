# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CLANG_TIDY_INCLUDED
MAKEFILE_LINT_C_CLANG_TIDY_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/clang/clang.mk
include $(MAKEFILEDIR)/configure/build-depends/clang-tidy/clang-tidy.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/tu.mk


_LINT_c_TU_h_clang_tidy := $(patsubst $(INCLUDEDIR)/%, $(builddir)/%.lint-c.clang-tidy.touch, $(TU_h))
_LINT_c_TU_c_clang_tidy := $(patsubst $(SRCLIBDIR)/%,  $(builddir)/%.lint-c.clang-tidy.touch, $(TU_c))
_LINT_c_TU_clang_tidy   := $(_LINT_c_TU_h_clang_tidy) $(_LINT_c_TU_c_clang_tidy)
_LINT_c_EX_clang_tidy   := $(patsubst %, %.lint-c.clang-tidy.touch, $(_EX_TU_src))
_LINT_c_clang_tidy      := $(_LINT_c_TU_clang_tidy) $(_LINT_c_EX_clang_tidy)


$(_LINT_c_TU_h_clang_tidy): $(builddir)/%.lint-c.clang-tidy.touch: $(INCLUDEDIR)/%
$(_LINT_c_TU_c_clang_tidy): $(builddir)/%.lint-c.clang-tidy.touch: $(SRCLIBDIR)/%
$(_LINT_c_TU_clang_tidy): %.lint-c.clang-tidy.touch: | %.d
$(_LINT_c_EX_clang_tidy): %.lint-c.clang-tidy.touch: %
$(_LINT_c_clang_tidy): $(CLANG_TIDY_CONF) $(MK) | $$(@D)/


$(_LINT_c_clang_tidy):
	$(info	$(INFO_)CLANG_TIDY	$@)
	$(CLANG_TIDY) $(CLANG_TIDYFLAGS_) $< -- $(CLANGFLAGS_) $(CPPFLAGS_) 2>&1 \
	| $(SED) '/generated\.$$/d' >&2
	$(TOUCH) $@


.PHONY: lint-c-clang-tidy
lint-c-clang-tidy: $(_LINT_c_clang_tidy);


endif  # include guard
