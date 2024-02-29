# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_VERSION_INCLUDED
MAKEFILE_CONFIGURE_VERSION_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils.mk
include $(MAKEFILEDIR)/configure/build-depends/git.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/verbose.mk


libname       := liba2i
DISTVERSION   := $(shell $(GIT) describe --dirty)
DISTNAME      := $(libname)-$(DISTVERSION)
DISTDATE      := $(shell $(GIT) log -1 --format='%aD' $(HIDE_ERR))
MAJOR_VERSION := $(shell $(ECHO) $(DISTVERSION) | $(CUT) -f1 -d. )
SONAME        := $(libname).so.$(MAJOR_VERSION)
REALNAME      := $(libname).so.$(DISTVERSION)
LINKERNAME    := $(libname).so


DISTFILESCMD := \
	$(FIND) $(srcdir) -not -type d \
	| $(GREP) -v '^$(srcdir)/.git$$' \
	| $(GREP) -v '^$(srcdir)/.git/' \
	| $(GREP) -v '^$(srcdir)/.tmp/' \
	| $(GREP) -v '^$(srcdir)/.checkpatch-camelcase.' \
	| $(SORT)

DISTDATECMD := \
	$(ECHO) '$(DISTVERSION)' \
	| if $(GREP) -- '-dirty$$' >/dev/null; then \
		$(DISTFILESCMD) \
		| $(XARGS) $(STAT) -c %y \
		| $(SORT) -n \
		| $(TAIL) -n1; \
	else \
		$(GIT) log -1 --format='%cD'; \
	fi;


DISTDATE := $(shell $(DISTDATECMD))


endif  # include guard
