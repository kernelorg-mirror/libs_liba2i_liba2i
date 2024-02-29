# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CHECK_CATMAN_GREP_INCLUDED
MAKEFILE_CHECK_CATMAN_GREP_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/man.mk


_CHECK_catman := $(patsubst %.cat.grep,%.check-catman.touch,$(_CHECK_catman_grep))


$(_CHECK_catman): %.check-catman.touch: %.cat.grep $(MK) | $$(@D)/
	$(info	$(INFO_)GREP		$@)
	! $(GREP) -n '.\{$(MANWIDTH)\}.' $< /dev/null >&2
	$(TOUCH) $@


.PHONY: check-catman-grep
check-catman-grep: $(_CHECK_catman);


endif  # include guard
