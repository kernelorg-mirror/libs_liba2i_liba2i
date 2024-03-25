# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_AR_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_AR_INCLUDED := 1


DEFAULT_ARFLAGS := qcsDP
EXTRA_ARFLAGS   :=
ARFLAGS         := $(DEFAULT_ARFLAGS) $(EXTRA_ARFLAGS)
AR              := gcc-ar


endif  # include guard
