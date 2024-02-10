# Copyright 2021-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_DIST_FILES_INCLUDED
MAKEFILE_DIST_FILES_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/git.mk
include $(MAKEFILEDIR)/configure/sed.mk
include $(MAKEFILEDIR)/dist/_.mk
include $(MAKEFILEDIR)/version.mk
include $(MAKEFILEDIR)/verbose.mk


DISTFILES   := $(shell $(GIT) ls-files $(HIDE_ERR) \
			| $(SED) 's,^,$(srcdir)/,' \
			| $(SED) 's,:,\\:,g')
_DISTFILES  := $(patsubst $(srcdir)/%,$(_DISTDIR)/%,$(DISTFILES))
_DISTPAGES  := $(filter     $(_DISTDIR)/share/man/man%,$(_DISTFILES))
_DISTOTHERS := $(filter-out $(_DISTDIR)/share/man/man%,$(_DISTFILES))


$(_DISTPAGES): $(_DISTDIR)/share/man/man%: $(srcdir)/share/man/man% $(MK) | $$(@D)/
	$(info INSTALL	$@)
	<$< \
	$(SED) "/^.TH/s/(date)/$$(git log --format=%cs -1 -- $< $(HIDE_ERR))/" \
	| $(SED) '/^.TH/s/(unreleased)/$(DISTVERSION)/' \
	| $(INSTALL_DATA) -T /dev/stdin $@

$(_DISTOTHERS): $(_DISTDIR)/%: $(srcdir)/% $(MK) | $$(@D)/
	$(info CP	$@)
	$(CP) -dT $< $@


endif  # include guard
