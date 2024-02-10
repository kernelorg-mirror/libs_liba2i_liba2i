# Copyright 2023-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_Z_INCLUDED
MAKEFILE_CONFIGURE_Z_INCLUDED := 1


DEFAULT_BZIP2FLAGS :=
EXTRA_BZIP2FLAGS   :=
BZIP2FLAGS         := $(DEFAULT_BZIP2FLAGS) $(EXTRA_BZIP2FLAGS)
BZIP2              := bzip2

DEFAULT_GZIPFLAGS  := -n
EXTRA_GZIPFLAGS    :=
GZIPFLAGS          := $(DEFAULT_GZIPFLAGS) $(EXTRA_GZIPFLAGS)
GZIP               := gzip

DEFAULT_LZIPFLAGS  :=
EXTRA_LZIPFLAGS    :=
LZIPFLAGS          := $(DEFAULT_LZIPFLAGS) $(EXTRA_LZIPFLAGS)
LZIP               := lzip

DEFAULT_XZFLAGS    :=
EXTRA_XZFLAGS      :=
XZFLAGS            := $(DEFAULT_XZFLAGS) $(EXTRA_XZFLAGS)
XZ                 := xz


endif  # include guard
