# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEV_INCLUDE_INCLUDED
MAKEFILE_BUILD_DEV_INCLUDE_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/src.mk


_TU_h := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%,$(TU_h))
_TU_c := $(patsubst $(SRCDIR)/%,$(builddir)/%,$(TU_c))


$(_TU_h): $(builddir)/%: $(INCLUDEDIR)/% $(MK) | $$(@D)/
	$(CP) -T $< $@

$(_TU_c): $(builddir)/%: $(SRCDIR)/% $(MK) | $$(@D)/
	$(CP) -T $< $@


.PHONY: build-dev-include
build-dev-include: $(_TU_h) $(_TU_c)
	@:


endif  # include guard
