# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_CPP_INCLUDED
MAKEFILE_CONFIGURE_CPP_INCLUDED := 1


include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/pkgconf.mk


DEFAULT_CPPFLAGS := $(shell $(PKGCONF_CMD) --cflags $(pc))
DEFAULT_CPPFLAGS += -I$(builddir)
EXTRA_CPPFLAGS   :=
CPPFLAGS         := $(DEFAULT_CPPFLAGS) $(EXTRA_CPPFLAGS)
CPP              := $(CC) $(CFLAGS) -E


endif  # include guard
