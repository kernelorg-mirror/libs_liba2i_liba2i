# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_INCLUDED
MAKEFILE_BUILD_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk


.PHONY: build
build: build-dev build-lib
	@:


.PHONY: clean
clean:
	$(info	RM -rf	$(builddir))
	$(RM) -rf $(builddir)


endif  # include guard
