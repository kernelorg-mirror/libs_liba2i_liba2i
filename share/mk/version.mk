# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_VERSION_INCLUDED
MAKEFILE_VERSION_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/git.mk
include $(MAKEFILEDIR)/verbose.mk


libname       := liba2i
DISTVERSION   := $(shell $(GIT) describe $(HIDE_ERR))
DISTNAME      := $(libname)-$(DISTVERSION)
DISTDATE      := $(shell $(GIT) log -1 --format='%aD')
MAJOR_VERSION := $(shell $(ECHO) $(DISTVERSION) | $(CUT) -f1 -d. )


endif  # include guard
