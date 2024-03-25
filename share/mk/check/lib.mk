# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CHECK_LIB_INCLUDED
MAKEFILE_CHECK_LIB_INCLUDED := 1


include $(MAKEFILEDIR)/build/lib/shared.mk
include $(MAKEFILEDIR)/build/lib/static.mk
include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/find.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/install/dev/include.mk
include $(MAKEFILEDIR)/install/lib/shared.mk
include $(MAKEFILEDIR)/install/lib/static.mk
include $(MAKEFILEDIR)/src/tu.mk


TESTS_c   := $(shell $(FIND) $(TESTSDIR) -type f | $(GREP) '\.c$$' | $(SORT))
TESTS_sh  := $(shell $(FIND) $(TESTSDIR) -type f | $(GREP) '\.sh$$' | $(SORT))
_TESTS_c  := $(patsubst $(srcdir)/share/%, $(builddir)/%.check, $(TESTS_c))
_TESTS_sh := $(patsubst $(srcdir)/share/%, $(builddir)/%.check.touch, $(TESTS_sh))
_tests_c  := $(patsubst $(srcdir)/share/%, $(builddir)/%.installcheck, $(TESTS_c))
_tests_sh := $(patsubst $(srcdir)/share/%, $(builddir)/%.installcheck.touch, $(TESTS_sh))


$(_TESTS_c): $(builddir)/%.check: $(srcdir)/share/% $(MK) $(TU_h) $(_LIB_a) $(_REALNAME) | $$(@D)/
	$(info	CHECK		$@)
	$(CC) $(CFLAGS) -o $@ $< $$(PKG_CONFIG_LIBDIR=$(PCDIR) $(PKGCONF) --cflags --libs liba2i)
	$@

$(_TESTS_sh): $(builddir)/%.check.touch: $(srcdir)/share/% $(MK) $(TU_h) $(_LIB_a) $(_REALNAME) | $$(@D)/
	$(info	CHECK		$@)
	PKG_CONFIG_LIBDIR=$(PCDIR) $<
	$(TOUCH) $@

$(_tests_c): $(builddir)/%.installcheck: $(srcdir)/share/% $(MK) $(_tu_h) $(_lib_a) $(_linkername) | $$(@D)/
	$(info	INSTALLCHECK	$@)
	$(CC) $(CFLAGS) -o $@ $< $$($(PKGCONF) --cflags --libs liba2i)
	$@

$(_tests_sh): $(builddir)/%.installcheck.touch: $(srcdir)/share/% $(MK) $(_tu_h) $(_lib_a) $(_linkername) | $$(@D)/
	$(info	INSTALLCHECK	$@)
	$<
	$(TOUCH) $@


.PHONY: check-lib
check-lib: $(_TESTS_c) $(_TESTS_sh)


.PHONY: installcheck-lib
installcheck-lib: $(_tests_c) $(_tests_sh)


endif  # include guard
