# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_SRC_INCLUDED
MAKEFILE_SRC_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/sed.mk
include $(MAKEFILEDIR)/configure/src.mk
include $(MAKEFILEDIR)/configure/version.mk


TU_h    := $(shell $(FIND) $(INCLUDEDIR) -type f | $(GREP) '\.h$$' | $(SORT))
TU_c    := $(shell $(FIND) $(SRCDIR)     -type f | $(GREP) '\.c$$' | $(SORT))
LIB_pc  := $(PCDIR)/$(libname)-uninstalled.pc


MANEXT := \(\.[[:digit:]]\([[:alpha:]][[:alnum:]]*\)\?\>\|\.man\)\+\(\.man\|\.in\)*$


MANPAGES := $(shell $(FIND) $(MANDIR)/* -type f \
		| $(GREP) '$(MANEXT)' \
		| $(SORT) \
		| $(SED) 's,:,\\:,g')


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval MAN$(s)DIR := $(MANDIR)/man$(s)))

$(foreach s, $(MANSECTIONS),                                                  \
	$(eval MAN$(s)PAGES :=                                                \
		$(filter $(MANDIR)/man$(s)/%,                                 \
			$(filter %.$(s),                                      \
				$(MANPAGES)))))


NONSO_MAN := $(shell $(FIND) $(MANDIR)/* -type f \
		| $(GREP) '$(MANEXT)' \
		| $(XARGS) $(GREP) -l '^\.TH ' \
		| $(SORT) \
		| $(SED) 's,:,\\:,g')


endif  # include guard
