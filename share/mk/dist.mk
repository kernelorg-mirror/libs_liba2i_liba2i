# Copyright 2021-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_DIST_INCLUDED
MAKEFILE_DIST_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/compress.mk
include $(MAKEFILEDIR)/install.mk
include $(MAKEFILEDIR)/version.mk
include $(MAKEFILEDIR)/verbose.mk


_DISTDIR := $(builddir)/dist


DEFAULT_TARFLAGS := \
	--sort=name \
	--owner=root:0 \
	--group=root:0 \
	--mtime='$(DISTDATE)'
EXTRA_TARFLAGS   :=
TARFLAGS         := $(DEFAULT_TARFLAGS) $(EXTRA_TARFLAGS)
TAR              := tar


DISTFILES   := $(shell $(GIT) ls-files $(HIDE_ERR) \
			| $(SED) 's,^,$(srcdir)/,' \
			| $(SED) 's,:,\\:,g')
_DISTFILES  := $(patsubst $(srcdir)/%,$(_DISTDIR)/%,$(DISTFILES))
_DISTPAGES  := $(filter     $(_DISTDIR)/share/man/man%,$(_DISTFILES))
_DISTOTHERS := $(filter-out $(_DISTDIR)/share/man/man%,$(_DISTFILES))

DISTFILE    := $(builddir)/$(DISTNAME).tar
compression := bz2 gz lz xz


$(builddir)/dist/:
	+$(info INSTALL	$@)
	+$(INSTALL_DIR) $@


$(builddir)/dist/%/: | $(builddir)/dist/
	+$(info INSTALL	$@)
	+$(INSTALL_DIR) $@


$(_DISTPAGES): $(_DISTDIR)/share/man/man%: $(srcdir)/share/man/man% $(MK) | $$(@D)/
	$(info INSTALL	$@)
	<$< \
	$(SED) "/^.TH/s/(date)/$$(git log --format=%cs -1 -- $< $(HIDE_ERR))/" \
	| $(SED) '/^.TH/s/(unreleased)/$(DISTVERSION)/' \
	| $(INSTALL_DATA) -T /dev/stdin $@

$(_DISTOTHERS): $(_DISTDIR)/%: $(srcdir)/% $(MK) | $$(@D)/
	$(info CP	$@)
	$(CP) -dT $< $@


$(DISTFILE): $(_DISTFILES) $(MK) | $$(@D)/
	$(info TAR	$@)
	$(TAR) $(TARFLAGS) -cf $@ -T /dev/null
	$(GIT) ls-files \
	| $(SED) 's,^,$(_DISTDIR)/,' \
	| $(XARGS) $(TAR) $(TARFLAGS) -rf $@ -C $(srcdir) \
		--transform 's,^$(_DISTDIR),$(DISTNAME),'

define DISTFILE_z_rule
$(DISTFILE).$(2): %.$(2): % $(MK) | $$$$(@D)/
	$$(info	$(1)	$$@)
	$($(1)) $($(1)FLAGS) -kf $$<
	touch $$@
endef

$(eval $(call DISTFILE_z_rule,BZIP2,bz2))
$(eval $(call DISTFILE_z_rule,GZIP,gz))
$(eval $(call DISTFILE_z_rule,LZIP,lz))
$(eval $(call DISTFILE_z_rule,XZ,xz))


.PHONY: dist-tar
dist-tar: $(DISTFILE);


$(foreach z, $(compression),                                                  \
	$(eval .PHONY: dist-$(z)))
$(foreach z, $(compression),                                                  \
	$(eval dist-$(z): $(DISTFILE).$(z);))
.PHONY: dist
dist: $(foreach z, $(compression), dist-$(z));


endif  # include guard
