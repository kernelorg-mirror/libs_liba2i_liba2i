# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_SRC_LIB_INCLUDED
MAKEFILE_SRC_LIB_INCLUDED := 1


include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/configure/version.mk


LIB_pc := $(PCDIR)/$(libname)-uninstalled.pc


endif  # include guard
