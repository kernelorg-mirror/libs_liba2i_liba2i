# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_INSTALL_INCLUDED
MAKEFILE_CONFIGURE_DIRECTORY_VARIABLES_INSTALL_INCLUDED := 1


include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/configure/version.mk


DESTDIR     :=
prefix      := /usr/local
exec_prefix := $(prefix)
includedir  := $(prefix)/include
datarootdir := $(prefix)/share
mandir      := $(datarootdir)/man
docdir      := $(datarootdir)/doc/$(projname)
htmldir     := $(docdir)/html
pdfdir      := $(docdir)/pdf
libdir      := $(exec_prefix)/lib
pcdir       := $(libdir)/pkgconfig


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval man$(s)dir := $(mandir)/man$(s)))
$(foreach s, $(MANSECTIONS),                                                  \
	$(eval man$(s)ext := .$(s)))


endif  # include guard
