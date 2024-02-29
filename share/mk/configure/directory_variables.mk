# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_INCLUDED
MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_INCLUDED := 1


include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/configure/version.mk


builddir := .tmp


DESTDIR     :=
prefix      := /usr/local
exec_prefix := $(prefix)/
includedir  := $(prefix)/include
datarootdir := $(prefix)/share
docdir      := $(datarootdir)/doc/$(libname)
mandir      := $(datarootdir)/man
htmldir     := $(docdir)/html
pdfdir      := $(docdir)/pdf
libdir      := $(exec_prefix)/lib
pcdir       := $(libdir)/pkgconfig


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval man$(s)dir := $(mandir)/man$(s)))
$(foreach s, $(MANSECTIONS),                                                  \
	$(eval man$(s)ext := .$(s)))


endif  # include guard
