# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_BUILD_EX_SRC_INCLUDED
MAKEFILE_BUILD_EX_SRC_INCLUDED := 1


include $(MAKEFILEDIR)/build/_.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/mandoc.mk
include $(MAKEFILEDIR)/configure/build-depends/sed.mk
include $(MAKEFILEDIR)/configure/directory_variables.mk
include $(MAKEFILEDIR)/src.mk


_UNITS_ex_src := \
	$(patsubst $(MANDIR)/%, $(_MANDIR)/%, \
		$(shell \
			$(FIND) $(MANDIR)/* -type f \
			| $(GREP) '$(MANEXT)' \
			| $(XARGS) $(GREP) -H '^\.\\" SRC BEGIN ' \
			| $(SED) 's,:\.\\" SRC BEGIN (,.d/,' \
			| $(SED) 's/)//' \
			| $(SORT) \
			| $(SED) 's,:,\\:,g' \
		) \
	)
_UNITS_ex_h := $(filter %.h,$(_UNITS_ex_src))
_UNITS_ex_c := $(filter %.c,$(_UNITS_ex_src))


$(_UNITS_ex_src): $$(patsubst $(_MANDIR)/%.d,$(MANDIR)/%,$$(@D)) $(MK) | $$(@D)/
$(_UNITS_ex_c):   $$(filter $$(@D)/%.h,$(_UNITS_ex_h))
$(_UNITS_ex_src):
	$(info	$(INFO_)SED		$@)
	<$< \
	$(SED) -n \
		-e '/^\.TH/,/^\.SH/{/^\.SH/!p}' \
		-e '/^\.SH EXAMPLES/p' \
		-e "/^\... SRC BEGIN ($(@F))$$/,/^\... SRC END$$/p" \
	| $(MANDOC) -Tutf8 \
	| $(HEAD) -n-2 \
	| $(SED) '/^[^ ]/d' \
	| $(SED) 's/^       //' \
	>$@


.PHONY: build-ex-src
build-ex-src: $(_UNITS_ex_src);


endif  # include guard
