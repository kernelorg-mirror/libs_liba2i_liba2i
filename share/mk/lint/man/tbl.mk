# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_LINT_MAN_TBL_INCLUDED
MAKEFILE_LINT_MAN_TBL_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/lint/man/_.mk
include $(MAKEFILEDIR)/src.mk


_LINT_man_tbl := \
	$(patsubst $(MANDIR)/%, $(_MANDIR)/%.lint-man.tbl.touch, $(NONSO_MAN))


$(_LINT_man_tbl): $(_MANDIR)/%.lint-man.tbl.touch: $(MANDIR)/% $(MK) | $$(@D)/
	$(info	$(INFO_)GREP		$@)
	if $(GREP) -q '^\.TS$$' $< && ! $(HEAD) -n1 $< | $(GREP) -q '\\" t$$'; \
	then \
		>&2 $(ECHO) "$<:1: missing '\\\" t' comment:"; \
		>&2 $(HEAD) -n1 <$<; \
		exit 1; \
	fi
	if $(HEAD) -n1 $< | $(GREP) -q '\\" t$$' && ! $(GREP) -q '^\.TS$$' $<; \
	then \
		>&2 $(ECHO) "$<:1: spurious '\\\" t' comment:"; \
		>&2 $(HEAD) -n1 <$<; \
		exit 1; \
	fi
	if $(TAIL) -n+2 <$< | $(GREP) -q '\\" t$$'; \
	then \
		>&2 $(ECHO) "$<: spurious '\\\" t' not in first line:"; \
		>&2 $(GREP) -n '\\" t$$' $< /dev/null; \
		exit 1; \
	fi
	$(TOUCH) $@


.PHONY: lint-man-tbl
lint-man-tbl: $(_LINT_man_tbl);


endif  # include guard
