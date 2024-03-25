# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_OBJ_AS_INCLUDED
MAKEFILE_BUILD_OBJ_AS_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/binutils/as.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/lib.mk
include $(MAKEFILEDIR)/src/tu.mk


_TU_o := $(patsubst $(LIBSRCDIR)/%, $(builddir)/%.o, $(TU_c))


$(_TU_o): %.o: $(MK) $(LIB_pc) | %.d $$(@D)/
$(_TU_o): $(builddir)/%.o: $(LIBSRCDIR)/%
	$(info	AS		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(AS) -O$$opt -c -o $(builddir)/$*.O$$opt.o $<; \
	done
	$(AS)         -c -o $@                      $<


.PHONY: build-obj-as
build-obj-as: $(_TU_o);


endif  # include guard
