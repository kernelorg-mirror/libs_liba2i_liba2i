# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_PS_TROFF_INCLUDED
MAKEFILE_BUILD_PS_TROFF_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/build/man/man.mk
include $(MAKEFILEDIR)/build/man/mdoc.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base/troff.mk


_PSMAN_MAN_set  := $(patsubst %, %.ps.set, $(_NONSO_MAN))
_PSMAN_MDOC_set := $(patsubst %, %.ps.set, $(_NONSO_MDOC))


$(_PSMAN_MAN_set): %.ps.set: %.ps.troff $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -man -Tps $(TROFFFLAGS_) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2

$(_PSMAN_MDOC_set): %.ps.set: %.ps.troff $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -mdoc -Tps $(TROFFFLAGS_) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2


.PHONY: build-ps-troff-man
build-ps-troff-man: $(_PSMAN_MAN_set);

.PHONY: build-ps-troff-mdoc
build-ps-troff-mdoc: $(_PSMAN_MDOC_set);

.PHONY: build-ps-troff
build-ps-troff: build-ps-troff-man build-ps-troff-mdoc;


endif  # include guard
