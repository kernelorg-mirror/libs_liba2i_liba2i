# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_VERSION_INCLUDED
MAKEFILE_VERSION_INCLUDED := 1


include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/verbose.mk


libname       := liba2i
DISTVERSION   := $(patsubst v%,%,$(shell $(GIT) describe $(HIDE_ERR) || $(ECHO) unreleased))
DISTNAME      := $(libname)-$(DISTVERSION)
MAJOR_VERSION := $(shell $(ECHO) $(DISTVERSION) | $(CUT) -f1 -d. )


endif  # include guard
