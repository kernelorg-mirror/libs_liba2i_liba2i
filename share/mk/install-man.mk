# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_MAN_INCLUDED
MAKEFILE_INSTALL_MAN_INCLUDED := 1


include $(MAKEFILEDIR)/install.mk
include $(MAKEFILEDIR)/src.mk


_man_man  := $(patsubst $(MANDIR)/%,$(_mandir)/%,$(MAN_man))


$(_man_man): $(_mandir)/%: $(MANDIR)/% $(MK) | $$(@D)/
	$(info	INSTALL		$@)
	$(INSTALL_DATA) -T $< $@


.PHONY: install-man
install-man: $(_man_man)
	@:


endif  # include guard
