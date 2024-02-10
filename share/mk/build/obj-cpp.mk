# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_OBJ_CPP_INCLUDED
MAKEFILE_BUILD_OBJ_CPP_INCLUDED := 1


include $(MAKEFILEDIR)/build/dev-src.mk
include $(MAKEFILEDIR)/configure/cpp.mk
include $(MAKEFILEDIR)/configure/pkgconf.mk


_TU_i := $(addsuffix .i,$(_TU_c))


$(_TU_i): %.i: % $(MK) $(_LIB_pc_u) | %.d $$(@D)/
	$(info	CPP		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CPP) $(CPPFLAGS) -O$$opt -o $*.O$$opt.i $<; \
	done
	$(CPP) $(CPPFLAGS)         -o $@          $<


.PHONY: build-obj-cpp
build-obj-cpp: $(_TU_i)
	@:


endif  # include guard
