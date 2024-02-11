# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_DIST_CHECK_INCLUDED
MAKEFILE_DIST_CHECK_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/diffoscope.mk
include $(MAKEFILEDIR)/configure/tar.mk
include $(MAKEFILEDIR)/dist/tar.mk
include $(MAKEFILEDIR)/version.mk


TMPDIR1 := $(shell $(MKTEMP) -d)
TMPDIR2 := $(shell $(MKTEMP) -d)


$(TMPDIR1)/$(DISTNAME).tar: $(DISTFILE) | $$(@D)/
	$(info	CP		$(TMPDIR1)/$(DISTNAME).tar)
	$(CP) $(DISTFILE) $(TMPDIR1)/$(DISTNAME).tar

$(TMPDIR1)/$(DISTNAME): $(TMPDIR1)/$(DISTNAME).tar | $$(@D)/
	$(info	TAR xf		$(TMPDIR1)/$(DISTNAME).tar)
	cd $(TMPDIR1)/ \
	&& $(TAR) xf $(TMPDIR1)/$(DISTNAME).tar

$(builddir)/distcheck.all.touch: $(TMPDIR1)/$(DISTNAME) | $$(@D)/
	$(info	MAKE		-C $(TMPDIR1)/$(DISTNAME) all)
	$(MAKE) -C $(TMPDIR1)/$(DISTNAME) all
	$(TOUCH) $@

$(builddir)/distcheck.install.touch: $(builddir)/distcheck.all.touch | $$(@D)/
	$(info	MAKE		-C $(TMPDIR1)/$(DISTNAME) install)
	$(MAKE) -C $(TMPDIR1)/$(DISTNAME) install DESTDIR=$(TMPDIR2)
	$(TOUCH) $@

$(TMPDIR1)/$(DISTNAME)/$(DISTFILE): $(builddir)/distcheck.install.touch | $$(@D)/
	$(info	MAKE		-C $(TMPDIR1)/$(DISTNAME) dist)
	$(MAKE) -C $(TMPDIR1)/$(DISTNAME) dist

$(builddir)/distcheck.diffoscope.touch: $(DISTFILE) $(TMPDIR1)/$(DISTNAME)/$(DISTFILE) | $$(@D)/
	$(info	DIFFOSCOPE	$(DISTFILE) $(TMPDIR1)/$(DISTNAME)/$(DISTFILE))
	$(DIFFOSCOPE) $(DISTFILE) $(TMPDIR1)/$(DISTNAME)/$(DISTFILE)
	$(TOUCH) $@


.PHONY: distcheck
distcheck: $(builddir)/distcheck.diffoscope.touch


endif  # include guard
