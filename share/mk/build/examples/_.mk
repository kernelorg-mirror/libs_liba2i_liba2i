# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_EX_DIR_INCLUDED
MAKEFILE_BUILD_EX_DIR_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/src.mk


_PAGEEXDIRS := $(patsubst $(MANDIR)/%,$(_MANDIR)/%.d/,$(NONSO_MAN))


$(_PAGEEXDIRS):
	+$(info	$(INFO_)MKDIR		$@)
	+$(MKDIR) -p $@
	+$(TOUCH) $@


.PHONY: build-ex
build-ex: build-ex-ld;


endif  # include guard
