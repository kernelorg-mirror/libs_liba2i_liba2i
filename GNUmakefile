# Copyright 2021-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-or-later WITH LGPL-3.0-linking-exception


BASH        := bash
SHELL       := /usr/bin/env
.SHELLFLAGS := -S '$(BASH) -Eeuo pipefail -c'


MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables


srcdir      := .
builddir    := .tmp
DATAROOTDIR := $(srcdir)/share
MAKEFILEDIR := $(DATAROOTDIR)/mk


.DEFAULT_GOAL := build


.PHONY: all
all: lint build check
	@:


.PHONY: extra
extra: all dist distcheck
	@:


.PHONY: help
help:
	$(info	Targets:)
	$(info	)
	$(info	all			Alias for "lint build check")
	$(info	extra			Alias for "all dist distcheck")
	$(info	)
	$(info	clean			Remove $$(builddir))
	$(info	)
	$(info	build (.DEFAULT_GOAL)	Wrapper for "build-lib build-dev")
	$(info	build-deps		Build the .d files)
	$(info	build-dev		Wrapper for build-dev-* targets)
	$(info	build-dev-src		Copy the source files)
	$(info	build-dev-pc		Build the pc(5) file)
	$(info	build-lib		Wrapper for build-lib-* targets)
	$(info	build-lib-shared	Build the shared library)
	$(info	build-lib-static	Build the static library)
	$(info	build-obj		Alias for "build-obj-as")
	$(info	build-obj-pch		Precompile headers)
	$(info	build-obj-cpp		Preprocess source TUs)
	$(info	build-obj-cc		Compile TUs)
	$(info	build-obj-as		Assemble TUs)
	$(info	check			Check the built library)
	$(info	)
	$(info	lint			Alias for "lint-c")
	$(info	lint-c			Wrapper for lint-c-* targets)
	$(info	lint-c-checkpatch	Lint C files with checkpatch(1))
	$(info	lint-c-clang-tidy	Lint C files with clang-tidy(1))
	$(info	lint-c-cppcheck		Lint C files with cppcheck(1))
	$(info	lint-c-cpplint		Lint C files with cpplint(1))
	$(info	lint-c-iwyu		Lint C files with iwyu(1))
	$(info	)
	$(info	install			Wrapper for install-* targets)
	$(info	install-dev		Wrapper for install-dev-* targets)
	$(info	install-dev-include	Install header files (.h))
	$(info	install-dev-pc		Install pc(5) file)
	$(info	install-lib		Wrapper for install-lib-* targets)
	$(info	install-lib-shared	Install shared library (.so))
	$(info	install-lib-static	Install static library (.a))
	$(info	install-man		Install manual pages)
	$(info	installcheck		Check the installed library)
	$(info	)
	$(info	# 'dist' is not available in release tarballs.)
	$(info	dist			Wrapper for dist-* targets)
	$(info	dist-tar		Create a release tarball)
	$(info	dist-z			Wrapper for dist-z-* targets)
	$(info	dist-z-bz2		Create a compressed tarball (.tar.bz2))
	$(info	dist-z-gz		Create a compressed tarball (.tar.gz))
	$(info	dist-z-lz		Create a compressed tarball (.tar.lz))
	$(info	dist-z-xz		Create a compressed tarball (.tar.xz))
	$(info	distcheck		Check the release tarball)
	$(info	)
	$(info	help			Print this help)
	$(info	help-variables		Print available variables, and default values)
	$(info	)
	$(info	nothing			Make nothing.  It's useful for debug purposes)
	$(info	)


.SECONDEXPANSION:


MK_ := $(wildcard $(addprefix $(MAKEFILEDIR)/, *.mk */*.mk))
MK  := $(srcdir)/GNUmakefile $(MK_)
include $(MK_)
$(MK):: ;


.PHONY: help-variables
help-variables:
	$(info	DISTVERSION	$$(git describe))
	$(info	DISTNAME	$(libname)-$$DISTVERSION)
	$(info	)
	$(info	HIDE_ERR	Define to empty string to debug some errors)
	$(info	)
	$(info	# Directory variables:)
	$(info	)
	$(info	builddir	.tmp)
	$(info	DESTDIR)
	$(info	prefix		/usr/local)
	$(info	exec_prefix	$$prefix)
	$(info	datarootdir	$$prefix/share)
	$(info	includedir	$$prefix/include)
	$(info	libdir		$$exec_prefix/lib)
	$(info	mandir		$$datarootdir/man)
	$(info	man{3,...}dir	$$mandir/man{3,...})
	$(info	pcdir		$$libdir/pkgconfig)
	$(info	)
	$(info	# Command variables (and flags):)
	$(info	)
	$(info	BASH)
	$(info	CP, CUT, ECHO, INSTALL, LN, MKTEMP, RM, SORT, TAC, TOUCH)
	$(info	INSTALL_DATA, INSTALL_DIR, INSTALL_PROGRAM)
	$(info	FIND, XARGS)
	$(info	GREP)
	$(info	SED)
	$(info	GIT)
	$(info	)
	$(info	PKGCONF, PKG_CONFIG	{EXTRA_,}PKGCONFFLAGS)
	$(info	)
	$(info	CPP			{EXTRA_,}CPPFLAGS)
	$(info	CC			{EXTRA_,}CCFLAGS)
	$(info	AS			{EXTRA_,}ASFLAGS)
	$(info	LD			{EXTRA_,}LDFLAGS, {EXTRA_,}LDLIBS)
	$(info	AR			{EXTRA_,}ARFLAGS)
	$(info	)
	$(info	CHECKPATCH		{EXTRA_,}CHECKPATCHFLAGS)
	$(info	CLANG_TIDY		{EXTRA_,}CLANG_TIDYFLAGS)
	$(info	CPPCHECK		{EXTRA_,}CPPCHECKFLAGS)
	$(info	CPPLINT			{EXTRA_,}CPPLINTFLAGS)
	$(info	IWYU			{EXTRA_,}IWYUFLAGS)
	$(info	)
	$(info	TAR			{EXTRA_,}TARFLAGS)
	$(info	BZIP2			{EXTRA_,}BZIP2FLAGS)
	$(info	GZIP			{EXTRA_,}GZIPFLAGS)
	$(info	LZIP			{EXTRA_,}LZIPFLAGS)
	$(info	XZ			{EXTRA_,}XZFLAGS)
	$(info	)


.PHONY: nothing
nothing:;


.DELETE_ON_ERROR:


FORCE:


include $(_TU_h_d)
include $(_TU_c_d)
