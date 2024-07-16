# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_RANLIB_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_RANLIB_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk


DEFAULT_RANLIBFLAGS :=
RANLIBFLAGS         :=
RANLIBFLAGS_        := $(DEFAULT_RANLIBFLAGS) $(RANLIBFLAGS)

ifeq ($(CC_VENDOR),gcc)
RANLIB              := gcc-ranlib
else
RANLIB              := ranlib
endif


endif  # include guard
