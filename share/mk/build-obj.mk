# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_OBJ_INCLUDED
MAKEFILE_BUILD_OBJ_INCLUDED := 1


include $(MAKEFILEDIR)/build.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/verbose.mk
include $(MAKEFILEDIR)/version.mk


_TU_gch   := $(addsuffix .gch,$(_TU_h))
_TU_i     := $(addsuffix .i,$(_TU_c))
_TU_s     := $(addsuffix .s,$(_TU_c))
_TU_o     := $(addsuffix .o,$(_TU_c))


$(_TU_gch): %.gch: % $(MK) $(_LIB_pc_u) | %.d $$(@D)/
	$(info	CC (pch)	$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CC) $(CPPFLAGS) $(CFLAGS) -O$$opt -c -o $*.O$$opt.gch $<; \
	done
	$(CC) $(CPPFLAGS) $(CFLAGS)         -c -o $@            $<

$(_TU_i): %.i: % $(MK) $(_LIB_pc_u) | %.d $$(@D)/
	$(info	CC (cpp)	$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CC) $(CPPFLAGS) $(CFLAGS) -O$$opt -E -o $*.O$$opt.i $<; \
	done
	$(CC) $(CPPFLAGS) $(CFLAGS)         -E -o $@          $<

$(_TU_s): %.s: % %.i $(MK) $(_LIB_pc_u) | %.d $$(@D)/
	$(info	CC		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CC) $(CPPFLAGS) $(CFLAGS) -O$$opt -S -o $*.O$$opt.s $<; \
	done
	$(CC) $(CPPFLAGS) $(CFLAGS)         -S -o $@          $<

$(_TU_o): %.c.o: %.c.s %.h.gch $(MK) $(_LIB_pc_u) | %.c.d $$(@D)/
	$(info	CC (as)		$@)
	for opt in g 0 1 2 s 3 fast; do \
	$(CC) $(CPPFLAGS) $(CFLAGS) -O$$opt -c -o $*.c.O$$opt.o $*.c.O$$opt.s; \
	done
	$(CC) $(CPPFLAGS) $(CFLAGS)         -c -o $@            $<


.PHONY: build-obj-pch
build-obj-pch: $(_TU_gch)
	@:

.PHONY: build-obj-cpp
build-obj-cpp: $(_TU_i)
	@:

.PHONY: build-obj-cc
build-obj-cc: $(_TU_s)
	@:

.PHONY: build-obj-as
build-obj-as: $(_TU_o)
	@:


.PHONY: build-obj
build-obj: build-obj-as
	@:


endif  # include guard
