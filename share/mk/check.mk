# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CHECK_INCLUDED
MAKEFILE_CHECK_INCLUDED := 1


include $(MAKEFILEDIR)/build-lib-shared.mk
include $(MAKEFILEDIR)/build-lib-static.mk
include $(MAKEFILEDIR)/configure-cc.mk
include $(MAKEFILEDIR)/install-dev.mk
include $(MAKEFILEDIR)/install-lib.mk
include $(MAKEFILEDIR)/src.mk


TESTS_c   := $(shell $(FIND) $(TESTSDIR) -type f | $(GREP) '\.c$$' | $(SORT))
TESTS_sh  := $(shell $(FIND) $(TESTSDIR) -type f | $(GREP) '\.sh$$' | $(SORT))
_TESTS_c  := $(patsubst $(srcdir)/share/%,$(builddir)/%.check,$(TESTS_c))
_TESTS_sh := $(patsubst $(srcdir)/share/%,$(builddir)/%.check.touch,$(TESTS_sh))
_tests_c  := $(patsubst $(srcdir)/share/%,$(builddir)/%.installcheck,$(TESTS_c))
_tests_sh := $(patsubst $(srcdir)/share/%,$(builddir)/%.installcheck.touch,$(TESTS_sh))


_TESTSDIRS := $(patsubst $(srcdir)/share/%,$(builddir)/%/,$(shell $(FIND) $(TESTSDIR) -type d | $(SORT)))


$(_TESTSDIRS): | $$(dir $$(@D))
	+$(info	MKDIR	$@)
	+$(MKDIR) -p $@


$(_TESTS_c): $(builddir)/%.check: $(srcdir)/share/% $(MK) $(TU_h) $(_LIB_a) $(_LIB_so_v) | $$(@D)/
	$(info	CHECK	$@)
	$(CC) $(CFLAGS) -o $@ $< $$(PKG_CONFIG_LIBDIR=$(PCDIR) $(PKGCONF) --cflags --libs liba2i)
	$@

$(_TESTS_sh): $(builddir)/%.check.touch: $(srcdir)/share/% $(MK) $(TU_h) $(_LIB_a) $(_LIB_so_v) | $$(@D)/
	$(info	CHECK	$@)
	PKG_CONFIG_LIBDIR=$(PCDIR) $<
	touch $@

$(_tests_c): $(builddir)/%.installcheck: $(srcdir)/share/% $(MK) $(_tu_h) $(_lib_a) $(_lib_so) | $$(@D)/
	$(info	INSTALLCHECK	$@)
	$(CC) $(CFLAGS) -o $@ $< $$($(PKGCONF) --cflags --libs liba2i)
	$@

$(_tests_sh): $(builddir)/%.installcheck.touch: $(srcdir)/share/% $(MK) $(_tu_h) $(_lib_a) $(_lib_so) | $$(@D)/
	$(info	INSTALLCHECK	$@)
	$<
	touch $@


.PHONY: check
check: $(_TESTS_c) $(_TESTS_sh)


.PHONY: installcheck
installcheck: $(_tests_c) $(_tests_sh)


endif  # include guard
