# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_EX_LD_INCLUDED
MAKEFILE_BUILD_EX_LD_INCLUDED := 1


include $(MAKEFILEDIR)/build/examples/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/binutils/ld.mk


_EX_TU_bin := $(patsubst %.o, %, $(_EX_TU_o))


$(_EX_TU_bin): %: %.o $(MK)
	$(info	$(INFO_)LD		$@)
	$(LD) $(LDFLAGS_) -o $@ $< $(LDLIBS_)


.PHONY: build-ex-ld
build-ex-ld: $(_EX_TU_bin);


endif  # include guard
