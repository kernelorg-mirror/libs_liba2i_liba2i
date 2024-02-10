# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_INCLUDED
MAKEFILE_LINT_C_INCLUDED := 1


linters_c := checkpatch clang-tidy cppcheck cpplint iwyu


.PHONY: lint-c
lint-c: $(foreach x,$(linters_c),lint-c-$(x))
	@:


endif  # include guard
