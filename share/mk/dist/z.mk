# Copyright 2021-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_DIST_Z_INCLUDED
MAKEFILE_DIST_Z_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/z.mk
include $(MAKEFILEDIR)/dist/tar.mk


compression := bz2 gz lz xz


define DISTFILE_z_rule
$(DISTFILE).$(2): %.$(2): % $(MK) | $$$$(@D)/
	$$(info	$(1)	$$@)
	$($(1)) $($(1)FLAGS) -kf $$<
	$(TOUCH) $$@
endef


$(eval $(call DISTFILE_z_rule,BZIP2,bz2))
$(eval $(call DISTFILE_z_rule,GZIP,gz))
$(eval $(call DISTFILE_z_rule,LZIP,lz))
$(eval $(call DISTFILE_z_rule,XZ,xz))


$(foreach z, $(compression),                                                  \
	$(eval .PHONY: dist-$(z)))
$(foreach z, $(compression),                                                  \
	$(eval dist-$(z): $(DISTFILE).$(z);))


.PHONY: dist-z
dist-z: $(foreach z, $(compression), dist-$(z));


endif  # include guard
