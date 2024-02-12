# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_LIB_SHARED_INCLUDED
MAKEFILE_BUILD_LIB_SHARED_INCLUDED := 1


include $(MAKEFILEDIR)/configure/ld.mk
include $(MAKEFILEDIR)/configure/pkgconf.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/verbose.mk
include $(MAKEFILEDIR)/version.mk


_LIB_so_v := $(builddir)/$(libname).so.$(DISTVERSION)


$(_LIB_so_v): %.so.$(DISTVERSION): $(TU_h) $(TU_c) $(MK) $(_LIB_pc_u) | $$(@D)/
	$(info	LD		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(LD) $(LDFLAGS) -O$$opt -o $*.O$$opt.so.$(DISTVERSION) $(TU_c) $(LDLIBS); \
	done
	$(LD) $(LDFLAGS)         -o $@                          $(TU_c) $(LDLIBS)


.PHONY: build-lib-shared
build-lib-shared: $(_LIB_so_v)
	@:


endif  # include guard
