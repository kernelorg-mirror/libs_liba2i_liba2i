# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_MAN_MANDOC_INCLUDED
MAKEFILE_LINT_MAN_MANDOC_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/mandoc.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/lint/man/_.mk
include $(MAKEFILEDIR)/src.mk


_LINT_man_mandoc := \
	$(patsubst $(MANDIR)/%, $(_MANDIR)/%.lint-man.mandoc.touch, $(NONSO_MAN))


mandoc_man_ignore_grep := $(MAKEFILEDIR)/lint/man/mandoc.ignore.grep


$(_LINT_man_mandoc): $(_MANDIR)/%.lint-man.mandoc.touch: $(MANDIR)/% $(mandoc_man_ignore_grep) $(MK) | $$(@D)/
	$(info	$(INFO_)MANDOC		$@)
	! ($(MANDOC) -man $(MANDOCFLAGS) $< 2>&1 \
	   | $(GREP) -v -f '$(mandoc_man_ignore_grep)' \
	   || $(TRUE); \
	) \
	| $(GREP) ^ >&2
	$(TOUCH) $@


.PHONY: lint-man-mandoc
lint-man-mandoc: $(_LINT_man_mandoc);


endif  # include guard
