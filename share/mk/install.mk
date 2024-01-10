# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_INCLUDED
MAKEFILE_INSTALL_INCLUDED := 1


DESTDIR      :=
prefix       := /usr/local
exec_prefix  := $(prefix)/
datarootdir  := $(prefix)/share
pcdir        := $(datarootdir)/pkgconfig
includedir   := $(prefix)/include
docdir       := $(datarootdir)/doc/$(libname)
pdfdir       := $(docdir)/pdf
libdir       := $(exec_prefix)/lib
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


_includedirs := $(patsubst $(INCLUDEDIR)/%,$(_includedir)/%/,$(TU_DIRS))


INSTALL         := install
INSTALL_DATA    := $(INSTALL) -m 644
INSTALL_DIR     := $(INSTALL) -m 755 -d
INSTALL_PROGRAM := $(INSTALL) -m 755


$(_includedirs): | $$(dir $$(@D))
	$(info	INSTALL		$@)
	$(INSTALL_DIR) $@

$(_man3dir)/ \
$(_man3headdir)/: $(_mandir)/
	$(info	INSTALL		$@)
	$(INSTALL_DIR) $@

$(_pdfdir)/: $(_docdir)/
	$(info	INSTALL		$@)
	$(INSTALL_DIR) $@

$(_pcdir)/ \
$(_docdir)/ \
$(_mandir)/: $(_datarootdir)/
	$(info	INSTALL		$@)
	$(INSTALL_DIR) $@

$(_libdir)/: $(_exec_prefix)/
	$(info	INSTALL		$@)
	$(INSTALL_DIR) $@

$(_exec_prefix)/ \
$(_datarootdir)/ \
$(_includedir)/: $(_prefix)/
	$(info	INSTALL		$@)
	$(INSTALL_DIR) $@

$(_prefix)/:
	$(info	INSTALL		$@)
	$(INSTALL_DIR) $@


.PHONY: install
install: install-dev install-lib install-man
	@:


endif  # include guard
