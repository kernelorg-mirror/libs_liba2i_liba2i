# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_PRE_PRECONV_INCLUDED
MAKEFILE_BUILD_PRE_PRECONV_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/src.mk


_MAN_tbl := $(patsubst $(MANDIR)/%,$(_MANDIR)/%.tbl,$(NONSO_MAN))


$(_MAN_tbl): $(_MANDIR)/%.tbl: $(MANDIR)/% $(MK) | $$(@D)/
	$(info	$(INFO_)PRECONV		$@)
	$(PRECONV) $(PRECONVFLAGS) $< >$@


.PHONY: build-pre-preconv
build-pre-preconv: $(_MAN_tbl);


endif  # include guard
