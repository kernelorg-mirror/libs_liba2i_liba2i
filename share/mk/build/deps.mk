# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_DEPS_INCLUDED
MAKEFILE_BUILD_DEPS_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/build/lib/shared.mk
include $(MAKEFILEDIR)/src/lib.mk
include $(MAKEFILEDIR)/src/tu.mk


_TU_h_d := $(patsubst $(INCLUDEDIR)/%, $(builddir)/%.d, $(TU_h))
_TU_c_d := $(patsubst $(LIBSRCDIR)/%,  $(builddir)/%.d, $(TU_c))
_TU_d   := $(_TU_h_d) $(_TU_c_d)


DEPTARGETS  = \
	-MT $(builddir)/$*.lint-c.checkpatch.touch \
	-MT $(builddir)/$*.lint-c.clang-tidy.touch \
	-MT $(builddir)/$*.lint-c.cppcheck.touch \
	-MT $(builddir)/$*.lint-c.cpplint.touch \
	-MT $(builddir)/$*.lint-c.iwyu.touch
DEPHTARGETS = \
	-MT $(builddir)/$*.gch \
	$(DEPTARGETS)
DEPCTARGETS = \
	-MT $(builddir)/$*.i \
	-MT $(builddir)/$*.s \
	-MT $(builddir)/$*.o \
	-MT $(_REALNAME) \
	$(DEPTARGETS)


$(_TU_d): $(MK) $(LIB_pc) | $$(@D)/


$(_TU_h_d): $(builddir)/%.d: $(INCLUDEDIR)/%
	$(CC) $(CFLAGS_) $(CPPFLAGS_) -M -MP $(DEPHTARGETS) -MF$@ $<

$(_TU_c_d): $(builddir)/%.d: $(LIBSRCDIR)/%
	$(CC) $(CFLAGS_) $(CPPFLAGS_) -M -MP $(DEPCTARGETS) -MF$@ $<


.PHONY: build-deps
build-deps: $(_TU_h_d) $(_TU_c_d);


endif  # include guard
