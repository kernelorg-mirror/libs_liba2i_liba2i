# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_PDF_TROFF_INCLUDED
MAKEFILE_BUILD_PDF_TROFF_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/src.mk


_PDFMAN_MAN_set  := $(patsubst $(MANDIR)/%,$(_MANDIR)/%.pdf.set,$(NONSO_MAN))


$(_PDFMAN_MAN_set): %.pdf.set: %.pdf.troff $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -man -Tpdf $(TROFFFLAGS) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2


.PHONY: build-pdf-troff-man
build-pdf-troff-man: $(_PDFMAN_MAN_set);

.PHONY: build-pdf-troff
build-pdf-troff: build-pdf-troff-man;


endif  # include guard
