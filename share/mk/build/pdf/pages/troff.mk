# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_PDF_PAGES_TROFF_INCLUDED
MAKEFILE_BUILD_PDF_PAGES_TROFF_INCLUDED := 1


include $(MAKEFILEDIR)/build/man/man.mk
include $(MAKEFILEDIR)/build/man/mdoc.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base/troff.mk


_PDFMAN_MAN_set  := $(patsubst %, %.pdf.set, $(_NONSO_MAN))
_PDFMAN_MDOC_set := $(patsubst %, %.pdf.set, $(_NONSO_MDOC))


$(_PDFMAN_MAN_set): %.pdf.set: %.pdf.troff $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -man -Tpdf $(TROFFFLAGS_) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2

$(_PDFMAN_MDOC_set): %.pdf.set: %.pdf.troff $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -mdoc -Tpdf $(TROFFFLAGS_) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2


.PHONY: build-pdf-pages-troff-man
build-pdf-pages-troff-man: $(_PDFMAN_MAN_set);

.PHONY: build-pdf-pages-troff-mdoc
build-pdf-pages-troff-mdoc: $(_PDFMAN_MDOC_set);

.PHONY: build-pdf-pages-troff
build-pdf-pages-troff: build-pdf-pages-troff-man build-pdf-pages-troff-mdoc;


endif  # include guard
