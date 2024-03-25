# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_IWYU_INCLUDED
MAKEFILE_LINT_C_IWYU_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/clang/clang.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/tac.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/true.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/iwyu/iwyu.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/tu.mk


_LINT_c_TU_h_iwyu := $(patsubst $(INCLUDEDIR)/%, $(builddir)/%.lint-c.iwyu.touch, $(TU_h))
_LINT_c_TU_c_iwyu := $(patsubst $(LIBSRCDIR)/%,  $(builddir)/%.lint-c.iwyu.touch, $(TU_c))
_LINT_c_TU_iwyu   := $(_LINT_c_TU_h_iwyu) $(_LINT_c_TU_c_iwyu)
_LINT_c_EX_iwyu   := $(patsubst %, %.lint-c.iwyu.touch, $(_EX_TU_src))
_LINT_c_iwyu      := $(_LINT_c_TU_iwyu) $(_LINT_c_EX_iwyu)


$(_LINT_c_TU_h_iwyu): $(builddir)/%.lint-c.iwyu.touch: $(INCLUDEDIR)/%
$(_LINT_c_TU_c_iwyu): $(builddir)/%.lint-c.iwyu.touch: $(LIBSRCDIR)/%
$(_LINT_c_TU_iwyu): %.lint-c.iwyu.touch: | %.d
$(_LINT_c_EX_iwyu): %.lint-c.iwyu.touch: %
$(_LINT_c_iwyu): $(MK) | $$(@D)/


$(_LINT_c_iwyu):
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
lint-c-iwyu: $(_LINT_c_iwyu);


endif  # include guard
