# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_HTML_TROFF_INCLUDED
MAKEFILE_BUILD_HTML_TROFF_INCLUDED := 1


include $(MAKEFILEDIR)/build/man/man.mk
include $(MAKEFILEDIR)/build/man/mdoc.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base/troff.mk


_HTMLMAN_MAN_set  := $(patsubst %, %.html.set, $(_NONSO_MAN))
_HTMLMAN_MDOC_set := $(patsubst %, %.html.set, $(_NONSO_MDOC))


$(_HTMLMAN_MAN_set): %.html.set: %.eqn $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -man -Thtml $(TROFFFLAGS) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2

$(_HTMLMAN_MDOC_set): %.html.set: %.eqn $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -mdoc -Thtml $(TROFFFLAGS) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2


.PHONY: build-html-troff-man
build-html-troff-man: $(_HTMLMAN_MAN_set);

.PHONY: build-html-troff-mdoc
build-html-troff-mdoc: $(_HTMLMAN_MDOC_set);

.PHONY: build-html-troff
build-html-troff: build-html-troff-man build-html-troff-mdoc;


endif  # include guard
