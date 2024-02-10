# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_CPPLINT_INCLUDED
MAKEFILE_CONFIGURE_CPPLINT_INCLUDED := 1


CPPLINT_CONF         := $(srcdir)/etc/cpplint/cpplint.cfg
DEFAULT_CPPLINTFLAGS :=
EXTRA_CPPLINTFLAGS   :=
CPPLINTFLAGS         := $(DEFAULT_CPPLINTFLAGS) $(EXTRA_CPPLINTFLAGS)
CPPLINT              := cpplint


endif  # include guard
