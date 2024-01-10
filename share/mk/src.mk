# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_SRC_INCLUDED
MAKEFILE_SRC_INCLUDED := 1


include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/version.mk


INCLUDEDIR  := $(srcdir)/include
SRCDIR      := $(srcdir)/src
LIBDIR      := $(srcdir)/lib
PCDIR       := $(DATAROOTDIR)/pkgconfig
MANDIR      := $(DATAROOTDIR)/man
TESTSDIR    := $(DATAROOTDIR)/tests


MANEXT := \.[[:digit:]]\([[:alpha:]][[:alnum:]]*\)\?\>\(\.man\|\.in\)*$


TU_h    := $(shell $(FIND) $(INCLUDEDIR) -type f | $(GREP) '\.h$$' | $(SORT))
TU_c    := $(shell $(FIND) $(SRCDIR)     -type f | $(GREP) '\.c$$' | $(SORT))
LIB_pc  := $(PCDIR)/$(libname)-uninstalled.pc
MAN_man := $(shell $(FIND) $(MANDIR)     -type f | $(GREP) '$(MANEXT)' | $(SORT))


TU_DIRS := $(filter-out $(INCLUDEDIR),$(shell $(FIND) $(INCLUDEDIR) -type d | $(SORT)))


endif  # include guard
