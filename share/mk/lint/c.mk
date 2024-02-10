# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_INCLUDED
MAKEFILE_LINT_C_INCLUDED := 1


include $(MAKEFILEDIR)/build/deps.mk
include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/cpp.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/version.mk


DEFAULT_IWYUFLAGS := -Xiwyu --no_fwd_decls
DEFAULT_IWYUFLAGS += -Xiwyu --error
EXTRA_IWYUFLAGS   :=
IWYUFLAGS         := $(DEFAULT_IWYUFLAGS) $(EXTRA_IWYUFLAGS)
IWYU              := iwyu


_TU_h_iwyu := $(addsuffix .lint-c.iwyu.touch,$(_TU_h))
_TU_c_iwyu := $(addsuffix .lint-c.iwyu.touch,$(_TU_c))
_TU_iwyu   := $(_TU_h_iwyu) $(_TU_c_iwyu)


$(_TU_iwyu): %.lint-c.iwyu.touch: % $(MK) | %.d $$(@D)/
	$(info	LINT (iwyu)		$@)
	$(IWYU) $(IWYUFLAGS) $(CPPFLAGS) $(CLANGCFLAGS) $< 2>&1 \
	| $(TAC) \
	| $(SED) '/correct/{N;d}' \
	| $(TAC) >&2
	$(TOUCH) $@


linters_c := checkpatch clang-tidy cppcheck cpplint iwyu
lint_c    := $(foreach x,$(linters_c),lint-c-$(x))


.PHONY: lint-c-iwyu
lint-c-iwyu: $(_TU_iwyu)
	@:


.PHONY: lint-c
lint-c: $(lint_c)
	@:


endif  # include guard
