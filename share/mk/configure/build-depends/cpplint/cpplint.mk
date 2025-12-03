# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_CPPLINT_CPPLINT_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_CPPLINT_CPPLINT_INCLUDED := 1


include $(MAKEFILEDIR)/configure/directory_variables/src.mk


CPPLINT_CONF         := $(SYSCONFDIR)/cpplint/cpplint.cfg
DEFAULT_CPPLINTFLAGS :=
CPPLINTFLAGS         :=
CPPLINTFLAGS_        := $(DEFAULT_CPPLINTFLAGS) $(CPPLINTFLAGS)
CPPLINT              := cpplint


endif  # include guard
