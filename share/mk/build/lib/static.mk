# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_LIB_STATIC_INCLUDED
MAKEFILE_BUILD_LIB_STATIC_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/obj/as.mk
include $(MAKEFILEDIR)/configure/build-depends/binutils/ar.mk
include $(MAKEFILEDIR)/configure/build-depends/binutils/ranlib.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/echo.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/rm.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/xargs.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/version.mk


_LIB_a := $(builddir)/$(libname).a


$(_LIB_a): %.a: $(_TU_o) $(MK) | $$(@D)/
	$(info	AR		$@)
	cd $(dir $@) && \
	for opt in g 0 1 2 s z 3 fast; do \
		$(RM) -f $(notdir $*.O$$opt.a); \
		$(ECHO) $(patsubst $(builddir)/%, %, $(_TU_o)) \
		| $(SED) "s,.o\>,.O$$opt.o," \
		| $(XARGS) $(AR) $(ARFLAGS_) $(notdir $*).O$$opt.a; \
		$(RANLIB) $(RANLIBFLAGS_) $(notdir $*).O$$opt.a; \
	done
	$(RM) -f $@
	cd $(dir $@)/ && \
	$(ECHO) $(patsubst $(builddir)/%, %, $(_TU_o)) \
	| $(XARGS) $(AR) $(ARFLAGS_) $(notdir $@); \
	$(RANLIB) $(RANLIBFLAGS_) $(notdir $@)


.PHONY: build-lib-static
build-lib-static: $(_LIB_a);


endif  # include guard
