# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_EX_LD_INCLUDED
MAKEFILE_BUILD_EX_LD_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/ld.mk


_UNITS_ex_bin := $(patsubst %.o,%,$(_UNITS_ex_o))


$(_UNITS_ex_bin): %: %.o $(MK)
	$(info	$(INFO_)LD		$@)
	$(LD) $(LDFLAGS) -o $@ $< $(LDLIBS)


.PHONY: build-ex-ld
build-ex-ld: $(_UNITS_ex_bin);


endif  # include guard
