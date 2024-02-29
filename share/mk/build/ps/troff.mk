# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_PS_TROFF_INCLUDED
MAKEFILE_BUILD_PS_TROFF_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/groff-base.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/src.mk


_PSMAN_MAN_set := $(patsubst $(MANDIR)/%,$(_MANDIR)/%.ps.set,$(NONSO_MAN))


$(_PSMAN_MAN_set): %.ps.set: %.ps.troff $(MK) | $$(@D)/
	$(info	$(INFO_)TROFF		$@)
	! ($(TROFF) -man -Tps $(TROFFFLAGS) <$< 2>&1 >$@) \
	| $(GREP) ^ >&2


.PHONY: build-ps-troff-man
build-ps-troff-man: $(_PSMAN_MAN_set);

.PHONY: build-ps-troff
build-ps-troff: build-ps-troff-man;


endif  # include guard
