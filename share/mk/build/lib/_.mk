# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_LIB_INCLUDED
MAKEFILE_BUILD_LIB_INCLUDED := 1


.PHONY: build-lib
build-lib: build-lib-shared build-lib-shared-allO build-lib-static;


endif  # include guard
