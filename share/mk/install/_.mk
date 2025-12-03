# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_INSTALL_INCLUDED
MAKEFILE_INSTALL_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils/install.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/rm.mk


%/:
	+$(info	$(INFO_)MKDIR		$@)
	+$(INSTALL_DIR) $@

%-rm:
	$(info	$(INFO_)RM		$*)
	$(RM) $*


.PHONY: install-all
install-all: install-dev install-lib install-man;

.PHONY: install
install: install-dev install-lib-shared install-man;

.PHONY: uninstall
uninstall: uninstall-dev uninstall-lib uninstall-man;


endif  # include guard
