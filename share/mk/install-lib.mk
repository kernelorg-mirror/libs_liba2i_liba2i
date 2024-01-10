# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_LIB_INCLUDED
MAKEFILE_INSTALL_LIB_INCLUDED := 1


include $(MAKEFILEDIR)/build.mk
include $(MAKEFILEDIR)/build-lib.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/install.mk
include $(MAKEFILEDIR)/src.mk


_lib_so   := $(_libdir)/$(libname).so
_lib_so_v := $(patsubst $(builddir)/%,$(_libdir)/%,$(_LIB_so_v))


$(_lib_so_v): $(_libdir)/%: $(builddir)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_PROGRAM) -T $< $@

$(_lib_so): $(_lib_so_v)
	$(info	LN		$@)
	$(LN) -sfT $@.$(MAJOR_VERSION) $@


.PHONY: install-lib
install-lib: $(_lib_so_v) $(_lib_so)
	@:


endif  # include guard
