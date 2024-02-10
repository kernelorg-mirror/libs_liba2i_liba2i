# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_DEV_INCLUDE_INCLUDED
MAKEFILE_INSTALL_DEV_INCLUDE_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/install/_.mk
include $(MAKEFILEDIR)/src.mk


_tu_h     := $(patsubst $(INCLUDEDIR)/%,$(_includedir)/%,$(TU_h))


$(_tu_h): $(_includedir)/%: $(INCLUDEDIR)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_DATA) -T $< $@


.PHONY: install-dev-include
install-dev-include: $(_tu_h)
	@:


endif  # include guard
