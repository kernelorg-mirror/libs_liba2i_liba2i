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


.PHONY: help
help:
	$(info	Targets:)
	$(info	)
	$(info	all			Alias for "lint build check")
	$(info	)
	$(info	clean			Remove $$(builddir))
	$(info	)
	$(info	build (.DEFAULT_GOAL)	Wrapper for "build-lib build-dev")
	$(info	)
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
	$(info	)
	$(info	lint			Alias for "lint-c")
	$(info	lint-c			Wrapper for lint-c-* targets)
	$(info	lint-c-checkpatch	Lint C files with checkpatch(1))
	$(info	lint-c-clang-tidy	Lint C files with clang-tidy(1))
	$(info	lint-c-cppcheck		Lint C files with cppcheck(1))
	$(info	lint-c-cpplint		Lint C files with cpplint(1))
	$(info	lint-c-iwyu		Lint C files with iwyu(1))
	$(info	)
	$(info	check			Check the built library)
	$(info	)
	$(info	install			Wrapper for install-* targets)
	$(info	install-dev		Wrapper for install-dev-* targets)
	$(info	install-dev-include	Install header files (.h))
	$(info	install-dev-pc		Install pc(5) file)
	$(info	install-lib		Wrapper for install-lib-* targets)
	$(info	install-lib-shared	Install shared library (.so))
	$(info	install-lib-static	Install static library (.a))
	$(info	install-man		Install manual pages)
	$(info	)
	$(info	installcheck		Check the installed library)
	$(info	)
	$(info	help			Print this help)


.SECONDEXPANSION:


MK_ := $(wildcard $(addprefix $(MAKEFILEDIR)/, *.mk */*.mk))
MK  := $(srcdir)/GNUmakefile $(MK_)
include $(MK_)
$(MK):: ;


.PHONY: nothing
nothing:;


.DELETE_ON_ERROR:


FORCE:


include $(_TU_h_d)
include $(_TU_c_d)
