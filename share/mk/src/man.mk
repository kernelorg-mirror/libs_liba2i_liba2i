# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_SRC_MAN_INCLUDED
MAKEFILE_SRC_MAN_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils/sort.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/find.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/xargs.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk


MANEXT := \(\.[[:digit:]]\([[:alpha:]][[:alnum:]]*\)\?\>\|\.man\)\+\(\.man\|\.in\)*$


MANPAGES := $(shell $(FIND) $(MANDIR)/* -type f \
		| $(GREP) '$(MANEXT)' \
		| $(SORT) \
		| $(SED) 's,:,\\:,g')


$(foreach s, $(MANSECTIONS),                                                  \
	$(eval MAN$(s)PAGES :=                                                \
		$(filter $(MAN$(s)DIR)/%,                                     \
			$(filter %.$(s),                                      \
				$(MANPAGES)))))


NONSO_MAN := $(shell $(FIND) $(MANDIR)/* -type f \
		| $(GREP) '$(MANEXT)' \
		| $(XARGS) $(GREP) -l '^\.TH ' \
		| $(SORT) \
		| $(SED) 's,:,\\:,g')
NONSO_MDOC := $(shell $(FIND) $(MANDIR)/* -type f \
		| $(GREP) '$(MANEXT)' \
		| $(XARGS) $(GREP) -l '^\.Dt ' \
		| $(SORT) \
		| $(SED) 's,:,\\:,g')
SO_MAN := $(filter-out $(NONSO_MAN) $(NONSO_MDOC), $(MANPAGES))


endif  # include guard
