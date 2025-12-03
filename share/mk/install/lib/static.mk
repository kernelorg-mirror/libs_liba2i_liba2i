# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_LIB_STATIC_INCLUDED
MAKEFILE_INSTALL_LIB_STATIC_INCLUDED := 1


include $(MAKEFILEDIR)/build/lib/static.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/install.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/install/lib/_.mk


_lib_a := $(patsubst $(builddir)/%, $(_libdir)/%, $(_LIB_a))


$(_lib_a): $(_libdir)/%: $(builddir)/% $(MK) | $$(@D)/
	$(info	$(INFO_)INSTALL		$@)
	$(INSTALL_DATA) -T $< $@


.PHONY: install-lib-static
install-lib-static: $(_lib_a);


endif  # include guard
