# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_HTML_TROFF_INCLUDED
MAKEFILE_BUILD_HTML_TROFF_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/src.mk


_HTMLMAN_MAN_set := $(patsubst $(MANDIR)/%,$(_MANDIR)/%.html.set,$(NONSO_MAN))


$(_HTMLMAN_MAN_set): %.html.set: %.eqn $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -man -Thtml $(TROFFFLAGS) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2


.PHONY: build-html-troff-man
build-html-troff-man: $(_HTMLMAN_MAN_set);

.PHONY: build-html-troff
build-html-troff: build-html-troff-man;


endif  # include guard
