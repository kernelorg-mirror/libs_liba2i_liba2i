# Copyright 2023-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_LZIP_LZIP_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_LZIP_LZIP_INCLUDED := 1


DEFAULT_LZIPFLAGS :=
LZIPFLAGS         :=
LZIPFLAGS_        := $(DEFAULT_LZIPFLAGS) $(LZIPFLAGS)
LZIP              := lzip


endif  # include guard
