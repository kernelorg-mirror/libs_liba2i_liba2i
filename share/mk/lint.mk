# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_INCLUDED
MAKEFILE_LINT_INCLUDED := 1


include $(MAKEFILEDIR)/src.mk


lint := lint-c


.PHONY: lint
lint: $(lint)
	@:


endif  # include guard
