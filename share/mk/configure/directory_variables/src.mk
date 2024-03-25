# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_SRC_INCLUDED
MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_SRC_INCLUDED := 1


INCLUDEDIR  := $(srcdir)/include
SYSCONFDIR  := $(srcdir)/etc
MANDIR      := $(srcdir)/man
LIBDIR      := $(srcdir)/lib
DATAROOTDIR := $(srcdir)/share
PCDIR       := $(LIBDIR)/pkgconfig
LIBSRCDIR   := $(LIBDIR)/src
TESTSDIR    := $(DATAROOTDIR)/tests


MANSECTIONS := $(patsubst $(MANDIR)/man%/, %, $(wildcard $(MANDIR)/man*/))


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval MAN$(s)DIR := $(MANDIR)/man$(s)))


endif  # include guard
