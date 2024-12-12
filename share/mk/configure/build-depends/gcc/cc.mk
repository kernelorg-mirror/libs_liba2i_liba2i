# Copyright 2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_GCC_CC_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_GCC_CC_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils/echo.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/verbose.mk


CC := gcc


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


COMMON_CFLAGS := \
	-O3 \
	-flto \
	-Wall \
	-Wextra \
	-Werror \
	-Wstrict-prototypes \
	-Wdeclaration-after-statement \
	-Wno-unknown-pragmas \
	-Wwrite-strings


GCC_CFLAGS := -fanalyzer


CLANG_CFLAGS := \
	-Weverything \
	-Wno-c++98-compat \
	-Wno-empty-translation-unit \
	-Wno-gnu-auto-type \
	-Wno-gnu-statement-expression \
	-Wno-language-extension-token \
	-Wno-pre-c11-compat \
	-Wno-unused-macros


DEFAULT_CFLAGS := $(COMMON_CFLAGS)

ifeq ($(CC_VENDOR),gcc)
DEFAULT_CFLAGS += $(GCC_CFLAGS)
else ifeq ($(CC_VENDOR),clang)
DEFAULT_CFLAGS += $(CLANG_CFLAGS)
endif

ifeq ($(CC_HAS_FFAT_LTO_OBJECTS),yes)
DEFAULT_CFLAGS += -ffat-lto-objects
endif

CFLAGS         :=
CFLAGS_        := $(DEFAULT_CFLAGS) $(CFLAGS)


endif  # include guard
