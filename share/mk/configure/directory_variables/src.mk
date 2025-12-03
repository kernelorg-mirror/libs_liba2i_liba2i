# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_SRC_INCLUDED
MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_SRC_INCLUDED := 1


INCLUDEDIR  := $(srcdir)/include
SYSCONFDIR  := $(srcdir)/etc
MANDIR      := $(srcdir)/man
LIBDIR      := $(srcdir)/lib
DATAROOTDIR := $(srcdir)/share
SRCDIR      := $(srcdir)/src
PCDIR       := $(LIBDIR)/pkgconfig
SRCLIBDIR   := $(SRCDIR)/lib
TESTSDIR    := $(DATAROOTDIR)/tests


MANSECTIONS := $(patsubst $(MANDIR)/man%/, %, $(wildcard $(MANDIR)/man*/))


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval MAN$(s)DIR := $(MANDIR)/man$(s)))


endif  # include guard
