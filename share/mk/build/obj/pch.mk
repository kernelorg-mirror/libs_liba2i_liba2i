# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_OBJ_PCH_INCLUDED
MAKEFILE_BUILD_OBJ_PCH_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/lib.mk
include $(MAKEFILEDIR)/src/tu.mk


_TU_gch := $(patsubst $(INCLUDEDIR)/%, $(builddir)/%.gch, $(TU_h))


$(_TU_gch): %.gch: $(MK) $(LIB_pc) | %.d $$(@D)/
$(_TU_gch): $(builddir)/%.gch: $(INCLUDEDIR)/%
	$(info	PCH		$@)
	for opt in g 0 1 2 s z 3 fast; do \
	$(CC) $(CFLAGS_) $(CPPFLAGS_) -O$$opt -c -o $(builddir)/$*.O$$opt.gch $<; \
	done
	$(CC) $(CFLAGS_) $(CPPFLAGS_)         -c -o $@                        $<


.PHONY: build-obj-pch
build-obj-pch: $(_TU_gch);


endif  # include guard
