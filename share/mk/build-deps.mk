# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEPS_INCLUDED
MAKEFILE_BUILD_DEPS_INCLUDED := 1


include $(MAKEFILEDIR)/build.mk
include $(MAKEFILEDIR)/configure-cc.mk
include $(MAKEFILEDIR)/configure-cpp.mk
include $(MAKEFILEDIR)/configure-pkgconf.mk
include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/src.mk
include $(MAKEFILEDIR)/version.mk


_TU_h := $(patsubst $(srcdir)/include/%,$(builddir)/%,$(TU_h))
_TU_c := $(patsubst $(srcdir)/src/%,$(builddir)/%,$(TU_c))

_TU_h_d   := $(addsuffix .d,$(_TU_h))
_TU_c_d   := $(addsuffix .d,$(_TU_c))


DEPTARGETS  = -MT $*.lint-c.checkpatch.touch \
              -MT $*.lint-c.clang-tidy.touch \
              -MT $*.lint-c.cppcheck.touch \
              -MT $*.lint-c.cpplint.touch \
              -MT $*.lint-c.iwyu.touch
DEPHTARGETS = $(DEPTARGETS) -MT $*.gch
DEPCTARGETS = $(DEPTARGETS) -MT $*.i


$(_TU_h): $(builddir)/%: $(srcdir)/include/% $(MK) | $$(@D)/
	$(CP) -T $< $@

$(_TU_c): $(builddir)/%: $(srcdir)/src/% $(MK) | $$(@D)/
	$(CP) -T $< $@

$(_TU_h_d): %.d: % $(_TU_h) $(MK) $(_LIB_pc_u) | $$(@D)/
	$(CC) $(CPPFLAGS) $(CFLAGS) -M -MP $(DEPHTARGETS) -MF$@ $<

$(_TU_c_d): %.d: % $(_TU_h) $(_TU_c) $(MK) $(_LIB_pc_u) | $$(@D)/
	$(CC) $(CPPFLAGS) $(CFLAGS) -M -MP $(DEPCTARGETS) -MF$@ $<


.PHONY: build-deps
build-deps: $(_TU_h_d) $(_TU_c_d)
	@:


endif  # include guard
