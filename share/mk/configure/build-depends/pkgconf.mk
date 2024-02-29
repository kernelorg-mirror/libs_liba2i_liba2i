# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_PKGCONF_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_PKGCONF_INCLUDED := 1


include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/configure/version.mk


# Compat
PKG_CONFIG := pkgconf


PKGCONF_ENV          := PKG_CONFIG_PATH=$(PCDIR)
DEFAULT_PKGCONFFLAGS :=
EXTRA_PKGCONFFLAGS   :=
PKGCONFFLAGS         := $(DEFAULT_PKGCONFFLAGS) $(EXTRA_PKGCONFFLAGS)
PKGCONF              := $(PKG_CONFIG)
PKGCONF_CMD          := $(PKGCONF_ENV) $(PKGCONF) $(PKGCONFFLAGS)


pc      := $(libname)-uninstalled
LIB_pc  := $(PCDIR)/$(pc).pc
pc_reqs := $(shell $(PKGCONF_CMD) --print-requires-private $(pc)) $(pc)


endif  # include guard
