# Copyright 2023-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_MAN_Z_INCLUDED
MAKEFILE_CONFIGURE_MAN_Z_INCLUDED := 1


Z :=
ifeq ($(Z),)
else ifeq ($(Z),.bz2)
else ifeq ($(Z),.gz)
else ifeq ($(Z),.lz)
else ifeq ($(Z),.xz)
else
$(warning "Z": "$(Z)")
$(error Valid values for "Z": ["", ".bz2", ".gz", ".lz", ".xz"])
endif


endif  # include guard
