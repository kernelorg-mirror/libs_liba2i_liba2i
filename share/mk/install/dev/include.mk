# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_DEV_INCLUDE_INCLUDED
MAKEFILE_INSTALL_DEV_INCLUDE_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils/install.mk
include $(MAKEFILEDIR)/configure/directory_variables/install.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/install/_.mk
include $(MAKEFILEDIR)/src/tu.mk


_includedir := $(DESTDIR)$(includedir)


_tu_h := $(patsubst $(INCLUDEDIR)/%, $(_includedir)/%, $(TU_h))


$(_tu_h): $(_includedir)/%: $(INCLUDEDIR)/% $(MK) | $$(@D)/
	$(info	$(INFO_)INSTALL		$@)
	$(INSTALL_DATA) -T $< $@


.PHONY: install-dev-include
install-dev-include: $(_tu_h);


endif  # include guard
