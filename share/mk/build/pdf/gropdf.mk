# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_PDF_GROPDF_INCLUDED
MAKEFILE_BUILD_PDF_GROPDF_INCLUDED := 1


include $(MAKEFILEDIR)/build/pdf/troff.mk
include $(MAKEFILEDIR)/configure/build-depends/groff.mk


_PDFMAN := $(patsubst %.pdf.set,%.pdf,$(_PDFMAN_MAN_set))


$(_PDFMAN): %.pdf: %.pdf.set $(MK) | $$(@D)/
	$(info	$(INFO_)GROPDF		$@)
	$(GROPDF) $(GROPDFFLAGS) <$< >$@


.PHONY: build-pdf-gropdf
build-pdf-gropdf: $(_PDFMAN);


endif  # include guard
