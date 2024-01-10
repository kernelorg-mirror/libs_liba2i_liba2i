# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_VERBOSE_INCLUDED
MAKEFILE_VERBOSE_INCLUDED := 1


ifdef V
HIDE_ERR :=
else
HIDE_ERR := 2>/dev/null
endif


V :=


$(V).SILENT:


endif  # include guard
