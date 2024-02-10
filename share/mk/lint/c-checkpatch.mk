# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CHECKPATCH_INCLUDED
MAKEFILE_LINT_C_CHECKPATCH_INCLUDED := 1


include $(MAKEFILEDIR)/build/dev-src.mk
include $(MAKEFILEDIR)/configure/checkpatch.mk
include $(MAKEFILEDIR)/configure/coreutils.mk


_TU_h_ckp  := $(addsuffix .lint-c.checkpatch.touch,$(_TU_h))
_TU_c_ckp  := $(addsuffix .lint-c.checkpatch.touch,$(_TU_c))
_TU_ckp    := $(_TU_h_ckp) $(_TU_c_ckp)


$(_TU_ckp): %.lint-c.checkpatch.touch: % $(CHECKPATCH_CONF) $(MK) | %.d $$(@D)/
	$(info	LINT (checkpatch)	$@)
	$(CHECKPATCH) $(CHECKPATCHFLAGS) -f $<
	$(TOUCH) $@


.PHONY: lint-c-checkpatch
lint-c-checkpatch: $(_TU_ckp)
	@:


endif  # include guard
