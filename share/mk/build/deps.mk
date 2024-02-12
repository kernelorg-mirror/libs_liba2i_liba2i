# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEPS_INCLUDED
MAKEFILE_BUILD_DEPS_INCLUDED := 1


include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/cpp.mk
include $(MAKEFILEDIR)/configure/pkgconf.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_d := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.d,$(TU_h))
_TU_c_d := $(patsubst $(SRCDIR)/%,$(builddir)/%.d,$(TU_c))
_TU_d   := $(_TU_h_d) $(_TU_c_d)


DEPTARGETS  = -MT $*.lint-c.checkpatch.touch \
              -MT $*.lint-c.clang-tidy.touch \
              -MT $*.lint-c.cppcheck.touch \
              -MT $*.lint-c.cpplint.touch \
              -MT $*.lint-c.iwyu.touch
DEPHTARGETS = $(DEPTARGETS) -MT $*.gch
DEPCTARGETS = $(DEPTARGETS) -MT $*.i


$(_TU_d): $(MK) $(_LIB_pc_u) | $$(@D)/


$(_TU_h_d): $(builddir)/%.d: $(INCLUDEDIR)/%
	$(CC) $(CPPFLAGS) $(CFLAGS) -M -MP $(DEPHTARGETS) -MF$@ $<

$(_TU_c_d): $(builddir)/%.d: $(SRCDIR)/%
	$(CC) $(CPPFLAGS) $(CFLAGS) -M -MP $(DEPCTARGETS) -MF$@ $<


.PHONY: build-deps
build-deps: $(_TU_h_d) $(_TU_c_d)
	@:


endif  # include guard
