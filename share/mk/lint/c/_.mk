# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_INCLUDED
MAKEFILE_LINT_C_INCLUDED := 1


.PHONY: lint-c
lint-c: \
	lint-c-clang-tidy \
	lint-c-cppcheck \
	lint-c-cpplint \
	lint-c-iwyu


endif  # include guard
