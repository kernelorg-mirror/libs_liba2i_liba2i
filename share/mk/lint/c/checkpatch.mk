# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_C_CHECKPATCH_INCLUDED
MAKEFILE_LINT_C_CHECKPATCH_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/examples/src.mk
include $(MAKEFILEDIR)/configure/build-depends/checkpatch/checkpatch.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/touch.mk
include $(MAKEFILEDIR)/configure/directory_variables/build.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk
include $(MAKEFILEDIR)/src/tu.mk


_LINT_c_TU_h_checkpatch := $(patsubst $(INCLUDEDIR)/%, $(builddir)/%.lint-c.checkpatch.touch, $(TU_h))
_LINT_c_TU_c_checkpatch := $(patsubst $(SRCLIBDIR)/%,  $(builddir)/%.lint-c.checkpatch.touch, $(TU_c))
_LINT_c_TU_checkpatch   := $(_LINT_c_TU_h_checkpatch) $(_LINT_c_TU_c_checkpatch)
_LINT_c_EX_checkpatch   := $(patsubst %, %.lint-c.checkpatch.touch, $(_EX_TU_src))
_LINT_c_checkpatch      := $(_LINT_c_TU_checkpatch) $(_LINT_c_EX_checkpatch)


$(_LINT_c_TU_h_checkpatch): $(builddir)/%.lint-c.checkpatch.touch: $(INCLUDEDIR)/%
$(_LINT_c_TU_c_checkpatch): $(builddir)/%.lint-c.checkpatch.touch: $(SRCLIBDIR)/%
$(_LINT_c_TU_checkpatch): %.lint-c.checkpatch.touch: | %.d
$(_LINT_c_EX_checkpatch): %.lint-c.checkpatch.touch: %
$(_LINT_c_checkpatch): $(CHECKPATCH_CONF) $(MK) | $$(@D)/


$(_LINT_c_checkpatch):
	$(info	$(INFO_)CHECKPATCH	$@)
	$(CHECKPATCH) $(CHECKPATCHFLAGS_) -f $< >&2
	$(TOUCH) $@


.PHONY: lint-c-checkpatch
lint-c-checkpatch: $(_LINT_c_checkpatch);


endif  # include guard
