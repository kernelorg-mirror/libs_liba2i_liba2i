# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_LIB_SHARED_INCLUDED
MAKEFILE_INSTALL_LIB_SHARED_INCLUDED := 1


include $(MAKEFILEDIR)/build/lib-shared.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/install.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/version.mk


_lib_so   := $(_libdir)/$(libname).so
_lib_so_v := $(patsubst $(builddir)/%,$(_libdir)/%,$(_LIB_so_v))


$(_lib_so_v): $(_libdir)/%: $(builddir)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_PROGRAM) -T $< $@

$(_lib_so): $(_lib_so_v)
	$(info	LN		$@)
	$(LN) -sfT $@.$(MAJOR_VERSION) $@


.PHONY: install-lib-shared
install-lib-shared: $(_lib_so_v) $(_lib_so)
	@:


endif  # include guard
