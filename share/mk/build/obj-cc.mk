# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_OBJ_CC_INCLUDED
MAKEFILE_BUILD_OBJ_CC_INCLUDED := 1


include $(MAKEFILEDIR)/build/dev-src.mk
include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/cpp.mk
include $(MAKEFILEDIR)/configure/pkgconf.mk


_TU_s := $(addsuffix .s,$(_TU_c))


$(_TU_s): %.s: % %.i $(MK) $(_LIB_pc_u) | %.d $$(@D)/
	$(info	CC		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CC) $(CPPFLAGS) $(CFLAGS) -O$$opt -S -o $*.O$$opt.s $<; \
	done
	$(CC) $(CPPFLAGS) $(CFLAGS)         -S -o $@          $<


.PHONY: build-obj-cc
build-obj-cc: $(_TU_s)
	@:


endif  # include guard
