# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_DEV_PC_INCLUDED
MAKEFILE_INSTALL_DEV_PC_INCLUDED := 1


include $(MAKEFILEDIR)/build/dev/pc.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/install.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/install.mk
include $(MAKEFILEDIR)/install/_.mk


_pcdir := $(DESTDIR)$(pcdir)


_lib_pc := $(_pcdir)/$(libname).pc


$(_lib_pc): $(LIB_pc) $(MK) | $$(@D)/
	$(info	$(INFO_)INSTALL		$@)
	$(INSTALL_DATA) -T $< $@
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


.PHONY: install-dev-pc
install-dev-pc: $(_lib_pc);


endif  # include guard
