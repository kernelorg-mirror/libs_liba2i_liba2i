# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_LIB_SHARED_INCLUDED
MAKEFILE_INSTALL_LIB_SHARED_INCLUDED := 1


include $(MAKEFILEDIR)/build/lib/shared.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/install.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/ln.mk
include $(MAKEFILEDIR)/configure/version.mk
include $(MAKEFILEDIR)/install/lib/_.mk


_realname   := $(_libdir)/$(REALNAME)
_soname     := $(_libdir)/$(SONAME)
_linkername := $(_libdir)/$(LINKERNAME)


$(_realname): $(_REALNAME) $(MK) | $$(@D)/
	$(info	$(INFO_)INSTALL		$@)
	$(INSTALL_PROGRAM) -T $< $@


$(_soname): $(_realname) $(MK) | $$(@D)/
	$(info	$(INFO_)LN		$@)
	$(LN) -sfT $(REALNAME) $@

$(_linkername): $(_soname)
	$(info	$(INFO_)LN		$@)
	$(LN) -sfT $(SONAME) $@


.PHONY: install-lib-shared
install-lib-shared: $(_realname) $(_soname) $(_linkername);


endif  # include guard
