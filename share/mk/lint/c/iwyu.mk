# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_IWYU_INCLUDED
MAKEFILE_LINT_C_IWYU_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/clang.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/iwyu.mk
include $(MAKEFILEDIR)/configure/build-depends/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_iwyu := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.iwyu.touch,$(TU_h))
_TU_c_iwyu := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.iwyu.touch,$(TU_c))
_TU_iwyu   := $(_TU_h_iwyu) $(_TU_c_iwyu)


$(_TU_h_iwyu): $(builddir)/%.lint-c.iwyu.touch: $(INCLUDEDIR)/%
$(_TU_c_iwyu): $(builddir)/%.lint-c.iwyu.touch: $(SRCDIR)/%
$(_TU_iwyu): %.lint-c.iwyu.touch: $(MK) | %.d $$(@D)/


$(_TU_iwyu):
	$(info	$(INFO_)IWYU		$@)
	! ($(IWYU) $(IWYUFLAGS) $(CPPFLAGS) $(CLANGFLAGS) $< 2>&1 \
	   | $(SED) -n '/should add these lines:/,$$p' \
	   | $(TAC) \
	   | $(SED) '/correct/{N;d}' \
	   | $(TAC) \
	   || $(TRUE); \
	) \
	| $(GREP) ^ >&2
	$(TOUCH) $@


.PHONY: lint-c-iwyu
lint-c-iwyu: $(_TU_iwyu);


endif  # include guard
