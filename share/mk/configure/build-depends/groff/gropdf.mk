# Copyright 2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_GROFF_GROPDF_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_GROFF_GROPDF_INCLUDED := 1


DEFAULT_GROPDFFLAGS :=
GROPDFFLAGS         :=
GROPDFFLAGS_        := $(DEFAULT_GROPDFFLAGS) $(GROPDFFLAGS)
GROPDF              := gropdf


endif  # include guard
