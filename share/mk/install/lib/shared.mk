# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_LIB_SHARED_INCLUDED
MAKEFILE_INSTALL_LIB_SHARED_INCLUDED := 1


include $(MAKEFILEDIR)/build/lib/shared.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/version.mk
include $(MAKEFILEDIR)/install/lib/_.mk


_linkername := $(_libdir)/$(LINKERNAME)
_realname   := $(_libdir)/$(REALNAME)


$(_realname): $(_REALNAME) $(MK) | $$(@D)/
	$(info	$(INFO_)INSTALL		$@)
	$(INSTALL_PROGRAM) -T $< $@

$(_linkername): $(_realname)
	$(info	$(INFO_)LN		$@)
	$(LN) -sfT $(SONAME) $@


.PHONY: install-lib-shared
install-lib-shared: $(_realname) $(_linkername);


endif  # include guard
