# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_AR_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_AR_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk


DEFAULT_ARFLAGS := qcDP
ARFLAGS         :=
ARFLAGS_        := $(DEFAULT_ARFLAGS) $(ARFLAGS)

ifeq ($(CC_VENDOR),gcc)
AR              := gcc-ar
else
AR              := ar
endif


endif  # include guard
