# Copyright 2021-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_DIST_TAR_INCLUDED
MAKEFILE_DIST_TAR_INCLUDED := 1


include $(MAKEFILEDIR)/configure/findutils.mk
include $(MAKEFILEDIR)/configure/git.mk
include $(MAKEFILEDIR)/configure/sed.mk
include $(MAKEFILEDIR)/configure/tar.mk
include $(MAKEFILEDIR)/dist/_.mk
include $(MAKEFILEDIR)/dist/files.mk
include $(MAKEFILEDIR)/version.mk


DISTFILE    := $(builddir)/$(DISTNAME).tar


$(DISTFILE): $(_DISTFILES) $(MK) | $$(@D)/
	$(info	TAR		$@)
	$(TAR) $(TARFLAGS) -cf $@ -T /dev/null
	$(GIT) ls-files \
	| $(SED) 's,^,$(_DISTDIR)/,' \
	| $(XARGS) $(TAR) $(TARFLAGS) -rf $@ -C $(srcdir) \
		--transform 's,^$(_DISTDIR),$(DISTNAME),'


.PHONY: dist-tar
dist-tar: $(DISTFILE);


endif  # include guard
