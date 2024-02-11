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


DISTFILESCMD      := $(GIT) ls-files $(HIDE_ERR) | $(SED) 's,^,$(srcdir)/,'
DISTFILESCMD_DIST := \
	$(FIND) $(srcdir) -not -type d \
	| $(GREP) -v '^$(srcdir)/.tmp/' \
	| $(GREP) -v '^$(srcdir)/.checkpatch-camelcase.'

DISTFILES    := $(shell $(DISTFILESCMD) | $(SED) 's,:,\\:,g')
_DISTFILES   := $(patsubst $(srcdir)/%,$(_DISTDIR)/%,$(DISTFILES))
_DISTPAGES   := $(filter $(_DISTDIR)/share/man/man%,$(_DISTFILES))
_DISTMK      := $(filter $(_DISTDIR)/share/mk/%,$(_DISTFILES))
_DISTOTHERS  := $(filter-out $(_DISTPAGES) $(_DISTMK), $(_DISTFILES))


$(_DISTPAGES): $(_DISTDIR)/share/man/man%: $(srcdir)/share/man/man% $(MK) | $$(@D)/
	$(info	SED		$@)
	<$< \
	$(SED) "/^.TH/s/(date)/$$($(GIT) log --format=%cs -1 -- $< $(HIDE_ERR))/" \
	| $(SED) '/^.TH/s/(unreleased)/$(DISTVERSION)/' \
	| $(INSTALL_DATA) -T /dev/stdin $@

$(_DISTMK): $(_DISTDIR)/share/mk/%: $(MAKEFILEDIR)/% $(MK) | $$(@D)/
	$(info	SED		$@)
	<$< \
	$(SED) 's/^DISTVERSION *:=.*/DISTVERSION := $(DISTVERSION)/' \
	| $(SED) 's/^DISTDATE *:=.*/DISTDATE := $(DISTDATE)/' \
	| $(SED) 's@^DISTFILESCMD *:=.*@DISTFILESCMD := $(DISTFILESCMD_DIST)@' \
	| $(INSTALL_DATA) -T /dev/stdin $@

$(_DISTOTHERS): $(_DISTDIR)/%: $(srcdir)/% $(MK) | $$(@D)/
	$(info	CP		$@)
	$(CP) -dT $< $@


endif  # include guard
