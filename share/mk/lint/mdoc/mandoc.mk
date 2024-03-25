# Copyright 2023-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_MDOC_MANDOC_INCLUDED
MAKEFILE_LINT_MDOC_MANDOC_INCLUDED := 1


include $(MAKEFILEDIR)/build/man/mdoc.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/true.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/mandoc/mandoc.mk


_LINT_mdoc_mandoc := $(patsubst %, %.lint-mdoc.mandoc.touch, $(_NONSO_MDOC))


mandoc_mdoc_ignore_grep := $(MAKEFILEDIR)/lint/mdoc/mandoc.ignore.grep


$(_LINT_mdoc_mandoc): %.lint-mdoc.mandoc.touch: % $(mandoc_mdoc_ignore_grep) $(MK) | $$(@D)/
	$(info	$(INFO_)MANDOC		$@)
	! ($(MANDOC) -mdoc $(MANDOCFLAGS) $< 2>&1 \
	   | $(GREP) -v -f '$(mandoc_mdoc_ignore_grep)' \
	   || $(TRUE); \
	) \
	| $(GREP) ^ >&2
	$(TOUCH) $@


.PHONY: lint-mdoc-mandoc
lint-mdoc-mandoc: $(_LINT_mdoc_mandoc);


endif  # include guard
