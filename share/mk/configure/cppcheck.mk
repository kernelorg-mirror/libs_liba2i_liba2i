# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_CPPCHECK_INCLUDED
MAKEFILE_CONFIGURE_CPPCHECK_INCLUDED := 1


CPPCHECK_CONF         := $(srcdir)/etc/cppcheck/cppcheck.suppress
DEFAULT_CPPCHECKFLAGS := --enable=all
DEFAULT_CPPCHECKFLAGS += --error-exitcode=2
DEFAULT_CPPCHECKFLAGS += --inconclusive
DEFAULT_CPPCHECKFLAGS += --quiet
DEFAULT_CPPCHECKFLAGS += --suppressions-list=$(CPPCHECK_CONF)
DEFAULT_CPPCHECKFLAGS += -D__GNUC__
DEFAULT_CPPCHECKFLAGS += -D__STDC_VERSION__=202000L
EXTRA_CPPCHECKFLAGS   :=
CPPCHECKFLAGS         := $(DEFAULT_CPPCHECKFLAGS) $(EXTRA_CPPCHECKFLAGS)
CPPCHECK              := cppcheck


endif  # include guard
