# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CHECKPATCH_INCLUDED
MAKEFILE_LINT_C_CHECKPATCH_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/checkpatch.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/src.mk


_TU_h_ckp := $(patsubst $(INCLUDEDIR)/%,$(builddir)/%.lint-c.checkpatch.touch,$(TU_h))
_TU_c_ckp := $(patsubst $(SRCDIR)/%,$(builddir)/%.lint-c.checkpatch.touch,$(TU_c))
_TU_ckp   := $(_TU_h_ckp) $(_TU_c_ckp)


$(_TU_h_ckp): $(builddir)/%.lint-c.checkpatch.touch: $(INCLUDEDIR)/%
$(_TU_c_ckp): $(builddir)/%.lint-c.checkpatch.touch: $(SRCDIR)/%
$(_TU_ckp): %.lint-c.checkpatch.touch: $(CHECKPATCH_CONF) $(MK) | %.d $$(@D)/


$(_TU_ckp):
	$(info	$(INFO_)CHECKPATCH	$@)
	$(CHECKPATCH) $(CHECKPATCHFLAGS) -f $<
	$(TOUCH) $@


.PHONY: lint-c-checkpatch
lint-c-checkpatch: $(_TU_ckp);


endif  # include guard
