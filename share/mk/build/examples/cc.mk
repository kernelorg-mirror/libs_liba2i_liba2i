# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_EX_CC_INCLUDED
MAKEFILE_BUILD_EX_CC_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp.mk


_UNITS_ex_o := $(patsubst %.c,%.o,$(_UNITS_ex_c))


$(_UNITS_ex_o): %.o: %.c $(MK)
	$(info	$(INFO_)CC		$@)
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<


.PHONY: build-ex-cc
build-ex-cc:  $(_UNITS_ex_o);


endif  # include guard
