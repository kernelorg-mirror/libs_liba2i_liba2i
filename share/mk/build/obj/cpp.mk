# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_OBJ_CPP_INCLUDED
MAKEFILE_BUILD_OBJ_CPP_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables.mk
include $(MAKEFILEDIR)/src.mk


_TU_i := $(patsubst $(SRCDIR)/%,$(builddir)/%.i,$(TU_c))


$(_TU_i): %.i: $(MK) $(LIB_pc) | %.d $$(@D)/
$(_TU_i): $(builddir)/%.i: $(SRCDIR)/%
	$(info	CPP		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CPP) $(CPPFLAGS) -O$$opt -o $(builddir)/$*.O$$opt.i $<; \
	done
	$(CPP) $(CPPFLAGS)         -o $@                      $<


.PHONY: build-obj-cpp
build-obj-cpp: $(_TU_i);


endif  # include guard
