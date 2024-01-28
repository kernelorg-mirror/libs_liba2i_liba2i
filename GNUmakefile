# Copyright 2021-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-or-later WITH LGPL-3.0-linking-exception


SHELL := /usr/bin/env
.SHELLFLAGS := -S bash -Eeuo pipefail -c


MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables


srcdir      := .
builddir    := .tmp
DATAROOTDIR := $(srcdir)/share
MAKEFILEDIR := $(DATAROOTDIR)/mk


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
	$(info	build			Wrapper for "build-lib build-dev")
	$(info	)
	$(info	build-deps		Build the .d files)
	$(info	build-dev		Wrapper for build-dev-* targets)
	$(info	build-dev-ar		Build the static library)
	$(info	build-dev-pc		Build the pc(5) file)
	$(info	build-lib		Alias for "build-lib-ld")
	$(info	build-lib-ld		Build the shared library)
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
	$(info	install			Wrapper for install-* targets)
	$(info	install-dev		Install development files (.h, .a, .pc))
	$(info	install-lib		Install shared library (.so))
	$(info	install-man		Install manual pages)
	$(info	)
	$(info	help			Print this help)


.SECONDEXPANSION:


MK_ := $(wildcard $(MAKEFILEDIR)/*.mk)
MK  := $(srcdir)/GNUmakefile $(MK_)
include $(MK_)
$(MK):: ;


.PHONY: nothing
nothing:;


.DELETE_ON_ERROR:


FORCE:


include $(_TU_h_d)
include $(_TU_c_d)
