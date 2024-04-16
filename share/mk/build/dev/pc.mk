# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEV_PC_INCLUDED
MAKEFILE_BUILD_DEV_PC_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/version.mk
include $(MAKEFILEDIR)/src/lib.mk


_LIB_pc := $(builddir)/$(libname).pc


$(_LIB_pc): $(LIB_pc) $(MK) | $$(@D)/
	$(info	SED		$@)
	$(SED) 's/^Version:.*/Version: $(DISTVERSION)/' <$< >$@
	$(SED) -i 's,^prefix=.*,prefix=$(prefix),' $@
ifneq ($(filter includedir=%,$(MAKEOVERRIDES)),)
	$(SED) -i 's,^includedir=.*,includedir=$(includedir),' $@
endif
ifneq ($(filter libdir=%,$(MAKEOVERRIDES)),)
	$(SED) -i 's,^libdir=.*,libdir=$(libdir),' $@
else
	$(SED) -i 's,^libdir=.*,libdir=$${exec_prefix}/lib,' $@
endif


.PHONY: build-dev-pc
build-dev-pc: $(_LIB_pc);


endif  # include guard
