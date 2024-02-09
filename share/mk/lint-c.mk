# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_INCLUDED
MAKEFILE_LINT_C_INCLUDED := 1


include $(MAKEFILEDIR)/build.mk
include $(MAKEFILEDIR)/configure-cc.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/version.mk


DEFAULT_CLANGFLAGS := -Weverything
DEFAULT_CLANGFLAGS += -Wno-c++98-compat
DEFAULT_CLANGFLAGS += -Wno-empty-translation-unit
DEFAULT_CLANGFLAGS += -Wno-extra-semi-stmt
DEFAULT_CLANGFLAGS += -Wno-gnu-auto-type
DEFAULT_CLANGFLAGS += -Wno-gnu-line-marker
DEFAULT_CLANGFLAGS += -Wno-gnu-statement-expression
DEFAULT_CLANGFLAGS += -Wno-language-extension-token
DEFAULT_CLANGFLAGS += -Wno-nullability-completeness
DEFAULT_CLANGFLAGS += -Wno-nullability-extension
DEFAULT_CLANGFLAGS += -Wno-pre-c2x-compat
DEFAULT_CLANGFLAGS += -Wno-unknown-attributes
DEFAULT_CLANGFLAGS += -Wno-unknown-warning-option
DEFAULT_CLANGFLAGS += -Wno-unused-command-line-argument
DEFAULT_CLANGFLAGS += -Wno-unused-macros
EXTRA_CLANGFLAGS   :=
CLANGFLAGS         := $(DEFAULT_CLANGFLAGS) $(EXTRA_CLANGFLAGS)

CHECKPATCH_CONF         := $(srcdir)/etc/checkpatch/checkpatch.conf
DEFAULT_CHECKPATCHFLAGS :=
EXTRA_CHECKPATCHFLAGS   :=
CHECKPATCHFLAGS         := $(DEFAULT_CHECKPATCHFLAGS) $(EXTRA_CHECKPATCHFLAGS)
CHECKPATCH              := checkpatch

CLANG-TIDY_CONF         := $(srcdir)/etc/clang-tidy/config.yaml
DEFAULT_CLANG-TIDYFLAGS := --config-file=$(CLANG-TIDY_CONF)
DEFAULT_CLANG-TIDYFLAGS += --quiet
DEFAULT_CLANG-TIDYFLAGS += --use-color
EXTRA_CLANG-TIDYFLAGS   :=
CLANG-TIDYFLAGS         := $(DEFAULT_CLANG-TIDYFLAGS) $(EXTRA_CLANG-TIDYFLAGS)
CLANG-TIDY              := clang-tidy

CPPLINT_CONF         := $(srcdir)/etc/cpplint/cpplint.cfg
DEFAULT_CPPLINTFLAGS :=
EXTRA_CPPLINTFLAGS   :=
CPPLINTFLAGS         := $(DEFAULT_CPPLINTFLAGS) $(EXTRA_CPPLINTFLAGS)
CPPLINT              := cpplint

CPPCHECK_CONF         := $(srcdir)/etc/cppcheck/cppcheck.suppress
DEFAULT_CPPCHECKFLAGS := --enable=all
DEFAULT_CPPCHECKFLAGS += --error-exitcode=2
DEFAULT_CPPCHECKFLAGS += --inconclusive
DEFAULT_CPPCHECKFLAGS += --quiet
DEFAULT_CPPCHECKFLAGS += --suppressions-list=$(CPPCHECK_CONF)
DEFAULT_CPPCHECKFLAGS += -D__GNUC__
DEFAULT_CPPCHECKFLAGS += -D__STDC_VERSION__=202000L
EXTRA_CPPCHECKFLAGS   :=
CPPCHECKFLAGS         := $(DEFAULT_CPPCHECKFLAGS) $(EXTRA_CPPCHECKFLAGS)
CPPCHECK              := cppcheck

DEFAULT_IWYUFLAGS := -Xiwyu --no_fwd_decls
DEFAULT_IWYUFLAGS += -Xiwyu --error
EXTRA_IWYUFLAGS   :=
IWYUFLAGS         := $(DEFAULT_IWYUFLAGS) $(EXTRA_IWYUFLAGS)
IWYU              := iwyu


_TU_h_ckp  := $(addsuffix .lint-c.checkpatch.touch,$(_TU_h))
_TU_c_ckp  := $(addsuffix .lint-c.checkpatch.touch,$(_TU_c))
_TU_ckp    := $(_TU_h_ckp) $(_TU_c_ckp)

_TU_h_ct   := $(addsuffix .lint-c.clang-tidy.touch,$(_TU_h))
_TU_c_ct   := $(addsuffix .lint-c.clang-tidy.touch,$(_TU_c))
_TU_ct     := $(_TU_h_ct) $(_TU_c_ct)

_TU_h_cck  := $(addsuffix .lint-c.cppcheck.touch,$(_TU_h))
_TU_c_cck  := $(addsuffix .lint-c.cppcheck.touch,$(_TU_c))
_TU_cck    := $(_TU_h_cck) $(_TU_c_cck)

_TU_h_cpl  := $(addsuffix .lint-c.cpplint.touch,$(_TU_h))
_TU_c_cpl  := $(addsuffix .lint-c.cpplint.touch,$(_TU_c))
_TU_cpl    := $(_TU_h_cpl) $(_TU_c_cpl)

_TU_h_iwyu := $(addsuffix .lint-c.iwyu.touch,$(_TU_h))
_TU_c_iwyu := $(addsuffix .lint-c.iwyu.touch,$(_TU_c))
_TU_iwyu   := $(_TU_h_iwyu) $(_TU_c_iwyu)


_LIB_cck := $(builddir)/$(libname).lint-c.cppcheck.touch


$(_TU_ckp): %.lint-c.checkpatch.touch: % $(CHECKPATCH_CONF) $(MK) | %.d $$(@D)/
	$(info	LINT (checkpatch)	$@)
	$(CHECKPATCH) $(CHECKPATCHFLAGS) -f $<
	$(TOUCH) $@

$(_TU_ct): %.lint-c.clang-tidy.touch: % $(CLANG-TIDY_CONF) $(MK) | %.d $$(@D)/
	$(info	LINT (clang-tidy)	$@)
	$(CLANG-TIDY) $(CLANG-TIDYFLAGS) $< -- \
	              $(CPPFLAGS) $(CFLAGS) $(CLANGFLAGS) 2>&1 \
	| $(SED) '/generated\.$$/d' >&2
	$(TOUCH) $@

$(_TU_cck): %.lint-c.cppcheck.touch: % $(CPPCHECK_CONF) $(MK) | %.d $$(@D)/
	$(info	LINT (cppcheck)		$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $<
	$(TOUCH) $@

$(_LIB_cck): %.lint-c.cppcheck.touch: $(_TU_c) $(_TU_h) $(CPPCHECK_CONF) $(MK) | $$(@D)/
	$(info	LINT (cppcheck)		$@)
	$(CPPCHECK) $(CPPCHECKFLAGS) -I $(INCLUDEDIR) $(_TU_c) $(_TU_h)
	$(TOUCH) $@

$(_TU_cpl): %.lint-c.cpplint.touch: % $(CPPLINT_CONF) $(MK) | %.d $$(@D)/
	$(info	LINT (cpplint)		$@)
	$(CPPLINT) $(CPPLINTFLAGS) $< >/dev/null
	$(TOUCH) $@

$(_TU_iwyu): %.lint-c.iwyu.touch: % $(MK) | %.d $$(@D)/
	$(info	LINT (iwyu)		$@)
	$(IWYU) $(IWYUFLAGS) $(CPPFLAGS) $(CFLAGS) $(CLANGFLAGS) $< 2>&1 \
	| $(TAC) \
	| $(SED) '/correct/{N;d}' \
	| $(TAC) >&2
	$(TOUCH) $@


linters_c := checkpatch clang-tidy cppcheck cpplint iwyu
lint_c    := $(foreach x,$(linters_c),lint-c-$(x))


.PHONY: lint-c-checkpatch
lint-c-checkpatch: $(_TU_ckp)
	@:

.PHONY: lint-c-clang-tidy
lint-c-clang-tidy: $(_TU_ct)
	@:

.PHONY: lint-c-cppcheck
lint-c-cppcheck: $(_TU_cck) $(_LIB_cck)
	@:

.PHONY: lint-c-cpplint
lint-c-cpplint: $(_TU_cpl)
	@:

.PHONY: lint-c-iwyu
lint-c-iwyu: $(_TU_iwyu)
	@:


.PHONY: lint-c
lint-c: $(lint_c)
	@:


endif  # include guard
