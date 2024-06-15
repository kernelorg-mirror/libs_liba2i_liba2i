# Copyright 2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_MAN_SO_INCLUDED
MAKEFILE_LINT_MAN_SO_INCLUDED := 1


include $(MAKEFILEDIR)/build/man/man.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/cut.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/find.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/xargs.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk


_LINT_man_so := $(patsubst %, %.lint-man.so.touch, $(_SO_MAN))


$(_LINT_man_so): %.lint-man.so.touch: % $(MK) | $$(@D)/
	$(info	$(INFO_)FIND		$@)
	$(GREP) '^\.so ' <$< \
	| $(CUT) -f2 -d' ' \
	| $(XARGS) -I {} $(FIND) '$(MANDIR)/{}' \
	>$@


.PHONY: lint-man-so
lint-man-so: $(_LINT_man_so);


endif  # include guard
