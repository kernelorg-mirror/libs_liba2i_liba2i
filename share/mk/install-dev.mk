# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_DEV_INCLUDED
MAKEFILE_INSTALL_DEV_INCLUDED := 1


include $(MAKEFILEDIR)/build.mk
include $(MAKEFILEDIR)/build-lib.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/install.mk
include $(MAKEFILEDIR)/src.mk


_tu_h     := $(patsubst $(INCLUDEDIR)/%,$(_includedir)/%,$(TU_h))
_lib_a    := $(patsubst $(builddir)/%,$(_libdir)/%,$(_LIB_a))
_lib_pc   := $(patsubst $(builddir)/%,$(_pcdir)/%,$(_LIB_pc))


$(_tu_h): $(_includedir)/%: $(INCLUDEDIR)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_DATA) -T $< $@

$(_lib_a): $(_libdir)/%: $(builddir)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_DATA) -T $< $@

$(_lib_pc): $(_pcdir)/%: $(builddir)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_DATA) -T $< $@


.PHONY: install-dev
install-dev: $(_tu_h) $(_lib_a) $(_lib_pc)
	@:


endif  # include guard
