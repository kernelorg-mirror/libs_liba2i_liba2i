# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_SRC_INCLUDED
MAKEFILE_CONFIGURE_SRC_INCLUDED := 1


INCLUDEDIR := $(srcdir)/include
SRCDIR     := $(srcdir)/src
LIBDIR     := $(srcdir)/lib
SYSCONFDIR := $(srcdir)/etc
PCDIR      := $(LIBDIR)/pkgconfig
MANDIR     := $(DATAROOTDIR)/man
TESTSDIR   := $(DATAROOTDIR)/tests


MANSECTIONS := $(patsubst $(MANDIR)/man%/, %, $(wildcard $(MANDIR)/man*/))


endif  # include guard
