# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_EX_CC_INCLUDED
MAKEFILE_BUILD_EX_CC_INCLUDED := 1


include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk


_EX_TU_o := $(patsubst %.c, %.o, $(_EX_TU_c))


$(_EX_TU_o): %.o: %.c $(MK)
	$(info	$(INFO_)CC		$@)
	$(CC) -c $(CFLAGS_) $(CPPFLAGS_) -o $@ $<


.PHONY: build-ex-cc
build-ex-cc:  $(_EX_TU_o);


endif  # include guard
