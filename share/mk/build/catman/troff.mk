# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_CATMAN_TROFF_INCLUDED
MAKEFILE_BUILD_CATMAN_TROFF_INCLUDED := 1


include $(MAKEFILEDIR)/build/man/man.mk
include $(MAKEFILEDIR)/build/man/mdoc.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/true.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base/nroff.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base/troff.mk


troff_catman_ignore_grep := $(MAKEFILEDIR)/build/catman/troff.ignore.grep


_CATMAN_MAN_set  := $(patsubst %, %.cat.set, $(_NONSO_MAN))
_CATMAN_MDOC_set := $(patsubst %, %.cat.set, $(_NONSO_MDOC))


$(_CATMAN_MAN_set): %.cat.set: %.cat.troff $(troff_catman_ignore_grep) $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -man $(TROFFFLAGS_) $(NROFFFLAGS_) <$< 2>&1 >$@ \
	   | $(GREP) -v -f '$(troff_catman_ignore_grep)' \
	   || $(TRUE); \
	) \
	| $(GREP) ^ >&2

$(_CATMAN_MDOC_set): %.cat.set: %.cat.troff $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -mdoc $(TROFFFLAGS_) $(NROFFFLAGS_) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2


.PHONY: build-catman-troff-man
build-catman-troff-man: $(_CATMAN_MAN_set);

.PHONY: build-catman-troff-mdoc
build-catman-troff-mdoc: $(_CATMAN_MDOC_set);

.PHONY: build-catman-troff
build-catman-troff: build-catman-troff-man build-catman-troff-mdoc;


endif  # include guard
