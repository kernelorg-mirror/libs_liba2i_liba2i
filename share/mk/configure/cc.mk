# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_CC_INCLUDED
MAKEFILE_CONFIGURE_CC_INCLUDED := 1


include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/grep.mk
include $(MAKEFILEDIR)/configure/sed.mk


export CC      := gcc


CC_VENDOR := \
	$(shell \
		$(CC) -v 2>&1 \
		| $(SED) -n '1p;$$p' \
		| $(SED) '/gcc version/s/.*/gcc/' \
		| $(SED) '/clang version/s/.*/clang/' \
		| $(SED) '/Apple LLVM version/s/.*/clang/' \
		| $(GREP) -e '^gcc$$' -e '^clang$$' \
		|| $(ECHO) unknown; \
	)


CC_HAS_FFAT_LTO_OBJECTS := \
	$(shell \
		$(CC) -Werror -ffat-lto-objects -S -x c -o /dev/null /dev/null $(HIDE_ERR) \
		&& $(ECHO) yes \
		|| $(ECHO) no; \
	)


GCC_CFLAGS := -fanalyzer


CLANG_CFLAGS := -Weverything
CLANG_CFLAGS += -Wno-c++98-compat
CLANG_CFLAGS += -Wno-empty-translation-unit
CLANG_CFLAGS += -Wno-gnu-auto-type
CLANG_CFLAGS += -Wno-gnu-statement-expression
CLANG_CFLAGS += -Wno-language-extension-token
CLANG_CFLAGS += -Wno-nullability-completeness
CLANG_CFLAGS += -Wno-nullability-extension
CLANG_CFLAGS += -Wno-unused-macros


DEFAULT_CFLAGS := -O3
DEFAULT_CFLAGS += -std=gnu11
DEFAULT_CFLAGS += -Wall
DEFAULT_CFLAGS += -Wextra
DEFAULT_CFLAGS += -Wstrict-prototypes
DEFAULT_CFLAGS += -Wdeclaration-after-statement
DEFAULT_CFLAGS += -Wno-unknown-pragmas

ifeq ($(CC_VENDOR),gcc)
DEFAULT_CFLAGS += $(GCC_CFLAGS)
else ifeq ($(CC_VENDOR),clang)
DEFAULT_CFLAGS += $(CLANG_CFLAGS)
endif

ifeq ($(CC_HAS_FFAT_LTO_OBJECTS),yes)
DEFAULT_CFLAGS += -flto
DEFAULT_CFLAGS += -ffat-lto-objects
endif

EXTRA_CFLAGS   :=
export CFLAGS  := $(DEFAULT_CFLAGS) $(EXTRA_CFLAGS)


CLANGCFLAGS := $(filter-out $(GCC_CFLAGS) -flto -ffat-lto-objects, $(CLANG_CFLAGS) $(CFLAGS))


endif  # include guard
