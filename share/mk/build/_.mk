# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_INCLUDED
MAKEFILE_BUILD_INCLUDED := 1


include $(MAKEFILEDIR)/configure/directory_variables/build.mk


_MANDIR := $(builddir)/man


.PHONY: build-all
build-all: \
	build-catman \
	build-dev \
	build-html \
	build-lib \
	build-man \
	build-obj \
	build-pdf \
	build-ps \
	build-ex;

.PHONY: build
build: \
	build-dev \
	build-lib-shared \
	build-man;


endif  # include guard
