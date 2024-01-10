# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_INCLUDED
MAKEFILE_BUILD_INCLUDED := 1


include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/src.mk



prefix := /usr/local


_TU_DIRS  := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%/,$(TU_DIRS))


$(_TU_DIRS): | $$(dir $$(@D))
	$(info	MKDIR	$@)
	$(MKDIR) $@

$(builddir)/:
	$(info	MKDIR	$@)
	$(MKDIR) $@


.PHONY: build
build: build-dev build-lib
	@:


.PHONY: clean
clean:
	$(info	RM -rf	$(builddir))
	$(RM) -rf $(builddir)


endif  # include guard
