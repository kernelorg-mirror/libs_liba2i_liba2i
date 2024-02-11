# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_DIST_CHECK_INCLUDED
MAKEFILE_DIST_CHECK_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/tar.mk
include $(MAKEFILEDIR)/dist/tar.mk
include $(MAKEFILEDIR)/version.mk


TMPDIR1 := $(shell $(MKTEMP) -d)
TMPDIR2 := $(shell $(MKTEMP) -d)


$(builddir)/distcheck.touch: $(DISTFILE) | $$(@D)/
	$(CP) $(DISTFILE) $(TMPDIR1)/$(DISTNAME).tar
	cd $(TMPDIR1); $(TAR) xf $(DISTNAME).tar
	$(MAKE) -C $(TMPDIR1)/$(DISTNAME) all
	$(MAKE) -C $(TMPDIR1)/$(DISTNAME) install DESTDIR=$(TMPDIR2)
	$(MAKE) -C $(TMPDIR1)/$(DISTNAME) dist
	$(TOUCH) $@


.PHONY: distcheck
distcheck: $(builddir)/distcheck.touch


endif  # include guard
