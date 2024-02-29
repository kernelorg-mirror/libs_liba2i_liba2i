# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_LIB_SHARED_INCLUDED
MAKEFILE_BUILD_LIB_SHARED_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/ld.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables.mk
include $(MAKEFILEDIR)/configure/verbose.mk
include $(MAKEFILEDIR)/configure/version.mk
include $(MAKEFILEDIR)/src.mk


_REALNAME := $(builddir)/$(REALNAME)


$(_REALNAME): %.so.$(DISTVERSION): $(TU_h) $(TU_c) $(MK) $(LIB_pc) | $$(@D)/
	$(info	LD		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(LD) $(LDFLAGS) -O$$opt -o $*.O$$opt.so.$(DISTVERSION) $(TU_c) $(LDLIBS); \
	done
	$(LD) $(LDFLAGS)         -o $@                          $(TU_c) $(LDLIBS)


.PHONY: build-lib-shared
build-lib-shared: $(_REALNAME);


endif  # include guard
