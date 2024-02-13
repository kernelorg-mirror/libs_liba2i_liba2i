# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CLANG_TIDY_INCLUDED
MAKEFILE_LINT_C_CLANG_TIDY_INCLUDED := 1


include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/clang.mk
include $(MAKEFILEDIR)/configure/clang-tidy.mk
include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/cpp.mk
include $(MAKEFILEDIR)/configure/sed.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_ct := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.clang-tidy.touch,$(TU_h))
_TU_c_ct := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.clang-tidy.touch,$(TU_c))
_TU_ct   := $(_TU_h_ct) $(_TU_c_ct)


$(_TU_ct): %.lint-c.clang-tidy.touch: $(CLANG_TIDY_CONF) $(MK) | %.d $$(@D)/


$(_TU_h_ct): $(builddir)/%.lint-c.clang-tidy.touch: $(INCLUDEDIR)/%
	$(info	CLANG_TIDY	$@)
	$(CLANG_TIDY) $(CLANG_TIDYFLAGS) $< -- $(CPPFLAGS) $(CLANGFLAGS) 2>&1 \
	| $(SED) '/generated\.$$/d' >&2
	$(TOUCH) $@

$(_TU_c_ct): $(builddir)/%.lint-c.clang-tidy.touch: $(SRCDIR)/%
	$(info	CLANG_TIDY	$@)
	$(CLANG_TIDY) $(CLANG_TIDYFLAGS) $< -- $(CPPFLAGS) $(CLANGFLAGS) 2>&1 \
	| $(SED) '/generated\.$$/d' >&2
	$(TOUCH) $@


.PHONY: lint-c-clang-tidy
lint-c-clang-tidy: $(_TU_ct)
	@:


endif  # include guard
