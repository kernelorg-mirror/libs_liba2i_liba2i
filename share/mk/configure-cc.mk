# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_CC_INCLUDED
MAKEFILE_CONFIGURE_CC_INCLUDED := 1


include $(MAKEFILEDIR)/cmd.mk


export CC      := gcc


CC_VENDOR := \
	$(shell \
		$(CC) -v 2>&1 \
		| $(SED) -n '1p;$$p' \
		| $(SED) '/gcc version/s/.*/gcc/' \
		| $(SED) '/clang version/s/.*/clang/' \
		| $(SED) '/Apple LLVM version/s/.*/clang/' \
		| grep -e '^gcc$$' -e '^clang$$' \
		|| echo unknown; \
	)


DEFAULT_CFLAGS := -O3
DEFAULT_CFLAGS += -std=gnu11
DEFAULT_CFLAGS += -flto
DEFAULT_CFLAGS += -Wall
DEFAULT_CFLAGS += -Wextra
DEFAULT_CFLAGS += -Wstrict-prototypes
DEFAULT_CFLAGS += -Wdeclaration-after-statement
DEFAULT_CFLAGS += -Wno-attributes
DEFAULT_CFLAGS += -Wno-nullability-completeness
DEFAULT_CFLAGS += -Wno-unknown-attributes
DEFAULT_CFLAGS += -Wno-unknown-pragmas
DEFAULT_CFLAGS += -Wno-unused-command-line-argument
EXTRA_CFLAGS   :=
export CFLAGS  := $(DEFAULT_CFLAGS) $(EXTRA_CFLAGS)


endif  # include guard
