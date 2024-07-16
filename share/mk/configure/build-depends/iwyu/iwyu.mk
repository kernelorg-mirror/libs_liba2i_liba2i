# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_IWYU_IWYU_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_IWYU_IWYU_INCLUDED := 1


DEFAULT_IWYUFLAGS := \
	-Xiwyu --no_fwd_decls \
	-Xiwyu --error
IWYUFLAGS         :=
IWYUFLAGS_        := $(DEFAULT_IWYUFLAGS) $(IWYUFLAGS)
IWYU              := iwyu


endif  # include guard
