# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CHECK_INCLUDED
MAKEFILE_CHECK_INCLUDED := 1


include $(MAKEFILEDIR)/build-dev.mk
include $(MAKEFILEDIR)/install-dev.mk
include $(MAKEFILEDIR)/install-lib.mk
include $(MAKEFILEDIR)/src.mk


TESTS  := $(shell $(FIND) $(TESTSDIR) -type f | $(GREP) '\.sh$$' | $(SORT))
_TESTS := $(patsubst $(srcdir)/share/%,$(builddir)/%.ck.touch,$(TESTS))
_tests := $(patsubst $(srcdir)/share/%,$(builddir)/%.ick.touch,$(TESTS))


_TESTSDIRS := $(patsubst $(srcdir)/share/%,$(builddir)/%/,$(shell $(FIND) $(TESTSDIR) -type d | $(SORT)))


$(_TESTSDIRS): | $$(dir $$(@D))
	$(info	MKDIR	$@)
	$(MKDIR) $@


$(_TESTS): $(builddir)/%.ck.touch: $(srcdir)/share/% $(MK) $(TU_h) $(_LIB_a) $(_LIB_so_v) | $$(@D)/
	$(info	SH (test)	$@)
	PKG_CONFIG_LIBDIR=$(PCDIR) $<
	touch $@

$(_tests): $(builddir)/%.ick.touch: $(srcdir)/share/% $(MK) $(_tu_h) $(_lib_a) $(_lib_so) | $$(@D)/
	$(info	SH (test)	$@)
	$<
	touch $@


.PHONY: check
check: $(_TESTS)


.PHONY: installcheck
installcheck: $(_tests)


endif  # include guard
