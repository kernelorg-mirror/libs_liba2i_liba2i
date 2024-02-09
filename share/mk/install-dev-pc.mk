# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_DEV_PC_INCLUDED
MAKEFILE_INSTALL_DEV_PC_INCLUDED := 1


include $(MAKEFILEDIR)/build/dev-pc.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/install.mk


_lib_pc   := $(patsubst $(builddir)/%,$(_pcdir)/%,$(_LIB_pc))


$(_lib_pc): $(_pcdir)/%: $(builddir)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_DATA) -T $< $@


.PHONY: install-dev-pc
install-dev-pc: $(_lib_pc)
	@:


endif  # include guard
