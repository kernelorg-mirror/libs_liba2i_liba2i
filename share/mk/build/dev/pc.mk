# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEV_PC_INCLUDED
MAKEFILE_BUILD_DEV_PC_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/version.mk
include $(MAKEFILEDIR)/src/lib.mk


_LIB_pc_u := $(builddir)/$(libname)-uninstalled.pc


$(_LIB_pc_u): $(LIB_pc) $(MK) | $$(@D)/
	$(info	SED		$@)
	$(SED) 's/^Version:.*/Version: $(DISTVERSION)/' <$< >$@
	$(SED) -i 's,^prefix=.*,prefix=$(srcdir),' $@
	$(SED) -i 's,^libdir=.*,libdir=$(builddir),' $@


.PHONY: build-dev-pc
build-dev-pc: $(_LIB_pc_u);


endif  # include guard
