# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_INCLUDED
MAKEFILE_INSTALL_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/version.mk


DESTDIR      :=
prefix       := /usr/local
exec_prefix  := $(prefix)/
datarootdir  := $(prefix)/share
includedir   := $(prefix)/include
docdir       := $(datarootdir)/doc/$(libname)
pdfdir       := $(docdir)/pdf
libdir       := $(exec_prefix)/lib
pcdir        := $(libdir)/pkgconfig
mandir       := $(datarootdir)/man
man3dir      := $(mandir)/man3
man3headdir  := $(mandir)/man3head


_prefix      := $(DESTDIR)$(prefix)
_exec_prefix := $(DESTDIR)$(exec_prefix)
_datarootdir := $(DESTDIR)$(datarootdir)
_pcdir       := $(DESTDIR)$(pcdir)
_includedir  := $(DESTDIR)$(includedir)
_docdir      := $(DESTDIR)$(docdir)
_pdfdir      := $(DESTDIR)$(pdfdir)
_libdir      := $(DESTDIR)$(libdir)
_mandir      := $(DESTDIR)$(mandir)
_man3dir     := $(DESTDIR)$(man3dir)
_man3headdir := $(DESTDIR)$(man3headdir)


%/:
	+$(info	MKDIR		$@)
	+$(INSTALL_DIR) $@


.PHONY: install
install: install-dev install-lib install-man
	@:


endif  # include guard
