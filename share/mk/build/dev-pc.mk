# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEV_PC_INCLUDED
MAKEFILE_BUILD_DEV_PC_INCLUDED := 1


include $(MAKEFILEDIR)/configure/pkgconf.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/install.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/version.mk


_LIB_pc   := $(builddir)/$(libname).pc


$(_LIB_pc_u): $(LIB_pc_u) $(MK) | $$(@D)/
	$(CP) -T $< $@

$(_LIB_pc): $(_LIB_pc_u) $(MK) | $$(@D)/
	$(info	SED		$@)
	$(SED) 's/Version:.*/Version: $(DISTVERSION)/' <$< >$@
	$(SED) -i 's,prefix=.*,prefix=$(prefix),' $@
ifneq ($(filter includedir=%,$(MAKEOVERRIDES)),)
	$(SED) -i 's,includedir=.*,includedir=$(includedir),' $@
endif
ifneq ($(filter libdir=%,$(MAKEOVERRIDES)),)
	$(SED) -i 's,libdir=.*,libdir=$(libdir),' $@
endif


.PHONY: build-dev-pc
build-dev-pc: $(_LIB_pc)
	@:


endif  # include guard
