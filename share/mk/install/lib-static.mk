# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_LIB_STATIC_INCLUDED
MAKEFILE_INSTALL_LIB_STATIC_INCLUDED := 1


include $(MAKEFILEDIR)/build/lib-static.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/install/_.mk
include $(MAKEFILEDIR)/src.mk


_lib_a    := $(patsubst $(builddir)/%,$(_libdir)/%,$(_LIB_a))


$(_lib_a): $(_libdir)/%: $(builddir)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_DATA) -T $< $@


.PHONY: install-lib-static
install-lib-static: $(_lib_a)
	@:


endif  # include guard
