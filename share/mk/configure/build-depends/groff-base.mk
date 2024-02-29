# Copyright 2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_GROFF_BASE_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_GROFF_BASE_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils.mk
include $(MAKEFILEDIR)/configure/build-depends/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/libc-bin.mk
include $(MAKEFILEDIR)/configure/build-depends/man.mk


DEFAULT_PRECONVFLAGS :=
EXTRA_PRECONVFLAGS   :=
PRECONVFLAGS         := $(DEFAULT_PRECONVFLAGS) $(EXTRA_PRECONVFLAGS)
PRECONV              := preconv


DEFAULT_PICFLAGS :=
EXTRA_PICFLAGS   :=
PICFLAGS         := $(DEFAULT_PICFLAGS) $(EXTRA_PICFLAGS)
PIC              := pic


TBL := tbl


DEFAULT_EQNFLAGS :=
EXTRA_EQNFLAGS   :=
EQNFLAGS         := $(DEFAULT_EQNFLAGS) $(EXTRA_EQNFLAGS)
EQN              := eqn


DEFAULT_TROFFFLAGS := -wbreak
EXTRA_TROFFFLAGS   :=
TROFFFLAGS         := $(DEFAULT_TROFFFLAGS) $(EXTRA_TROFFFLAGS)
TROFF              := troff


TROFF_CHECKSTYLE_LVL := 3
NROFF_LINE_LENGTH    := $(shell $(EXPR) $(MANWIDTH) - 2)
NROFF_OUT_DEVICE     := \
	$(shell $(LOCALE) charmap \
		| $(GREP) -i 'utf-*8' >/dev/null \
		&& $(ECHO) utf8 \
		|| $(ECHO) ascii \
	)

DEFAULT_NROFFFLAGS := \
	-T$(NROFF_OUT_DEVICE) \
	-rLL=$(NROFF_LINE_LENGTH)n \
	-rCHECKSTYLE=$(TROFF_CHECKSTYLE_LVL) \
	-ww
EXTRA_NROFFFLAGS   :=
NROFFFLAGS         := $(DEFAULT_NROFFFLAGS) $(EXTRA_NROFFFLAGS)


DEFAULT_GROTTYFLAGS := -c
EXTRA_GROTTYFLAGS   :=
GROTTYFLAGS         := $(DEFAULT_GROTTYFLAGS) $(EXTRA_GROTTYFLAGS)
GROTTY              := grotty


DEFAULT_GROPSFLAGS :=
EXTRA_GROPSFLAGS   :=
GROPSFLAGS         := $(DEFAULT_GROPSFLAGS) $(EXTRA_GROPSFLAGS)
GROPS              := grops


endif  # include guard
