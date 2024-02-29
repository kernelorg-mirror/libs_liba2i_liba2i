# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_INCLUDED
MAKEFILE_INSTALL_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk


%/:
	+$(info	$(INFO_)MKDIR		$@)
	+$(INSTALL_DIR) $@

%-rm:
	$(info	$(INFO_)RM		$*)
	$(RM) $*


.PHONY: install
install: install-dev install-lib install-man;

.PHONY: uninstall
uninstall: uninstall-dev uninstall-lib uninstall-man;


endif  # include guard
