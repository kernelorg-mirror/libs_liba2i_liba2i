# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_OBJ_CC_INCLUDED
MAKEFILE_BUILD_OBJ_CC_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/lib.mk
include $(MAKEFILEDIR)/src/tu.mk


_TU_s := $(patsubst $(SRCDIR)/%, $(builddir)/%.s, $(TU_c))


$(_TU_s): %.s: $(MK) $(LIB_pc) | %.d $$(@D)/
$(_TU_s): $(builddir)/%.s: $(SRCDIR)/%
	$(info	CC		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CC) $(CPPFLAGS) $(CFLAGS) -O$$opt -S -o $(builddir)/$*.O$$opt.s $<; \
	done
	$(CC) $(CPPFLAGS) $(CFLAGS)         -S -o $@                      $<


.PHONY: build-obj-cc
build-obj-cc: $(_TU_s);


endif  # include guard
