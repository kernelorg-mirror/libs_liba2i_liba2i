# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_LIB_INCLUDED
MAKEFILE_INSTALL_LIB_INCLUDED := 1


include $(MAKEFILEDIR)/configure/directory_variables/install.mk


_libdir := $(DESTDIR)$(libdir)


.PHONY: install-lib
install-lib: install-lib-shared install-lib-static;


endif  # include guard
