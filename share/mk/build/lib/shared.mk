# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_LIB_SHARED_INCLUDED
MAKEFILE_BUILD_LIB_SHARED_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/binutils/ld.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/verbose.mk
include $(MAKEFILEDIR)/configure/version.mk
include $(MAKEFILEDIR)/src/tu.mk


_REALNAME   := $(builddir)/$(REALNAME)
_SONAME     := $(builddir)/$(SONAME)
_LINKERNAME := $(builddir)/$(LINKERNAME)

_REALNAME_ALLO := $(_REALNAME).allO.touch


$(_REALNAME_ALLO): %.so.$(DISTVERSION).allO.touch: $(TU_h) $(TU_c) $(MK) $(LIB_pc) | $$(@D)/
	$(info	$(INFO_)LD		$@)
	for opt in g 0 1 2 s z 3 fast; do \
	$(LD) $(LDFLAGS_) -O$$opt -o $*.O$$opt.so.$(DISTVERSION) $(TU_c) $(LDLIBS_); \
	done
	$(TOUCH) $@


$(_REALNAME): %.so.$(DISTVERSION): $(TU_h) $(TU_c) $(MK) $(LIB_pc) | $$(@D)/
	$(info	$(INFO_)LD		$@)
	$(LD) $(LDFLAGS_)         -o $@                          $(TU_c) $(LDLIBS_)


$(_SONAME): $(_REALNAME) $(MK) | $$(@D)/
	$(info	$(INFO_)LN		$@)
	$(LN) -sfT $(REALNAME) $@


$(_LINKERNAME): $(_SONAME) $(MK) | $$(@D)/
	$(info	$(INFO_)LN		$@)
	$(LN) -sfT $(SONAME) $@


.PHONY: build-lib-shared
build-lib-shared: $(_LINKERNAME);

.PHONY: build-lib-shared-allO
build-lib-shared-allO: $(_REALNAME_ALLO);


endif  # include guard
