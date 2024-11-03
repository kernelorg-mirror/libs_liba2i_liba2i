# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_LD_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_LD_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk
include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/coreutils/echo.mk
include $(MAKEFILEDIR)/configure/build-depends/pkgconf/pkgconf.mk
include $(MAKEFILEDIR)/configure/build-depends/sed/sed.mk
include $(MAKEFILEDIR)/configure/verbose.mk
include $(MAKEFILEDIR)/configure/version.mk


LD := $(CC) $(CFLAGS_) $(CPPFLAGS_)


LD_HAS_FUSE_LINKER_PLUGIN := \
	$(shell \
		$(ECHO) 'int main(void) {}' \
		| $(LD) -fuse-linker-plugin -x c -o /dev/null /dev/stdin $(HIDE_ERR) \
		&& $(ECHO) yes \
		|| $(ECHO) no; \
	)


DEFAULT_LDFLAGS := \
	-shared \
	-Wl,-soname,$(SONAME) \
	-Wl,--as-needed \
	-Wl,--no-allow-shlib-undefined \
	-Wl,--no-copy-dt-needed-entries \
	-Wl,--no-undefined \
	$(shell $(PKGCONF_CMD) --libs-only-L $(pc_reqs) $(HIDE_ERR)) \
	$(shell $(PKGCONF_CMD) --libs-only-other $(pc_reqs) $(HIDE_ERR))

ifeq ($(LD_HAS_FUSE_LINKER_PLUGIN),yes)
DEFAULT_LDFLAGS += -fuse-linker-plugin
endif

LDFLAGS         :=
LDFLAGS_        := $(DEFAULT_LDFLAGS) $(LDFLAGS)


DEFAULT_LDLIBS := \
	$(filter-out -la2i, $(shell $(PKGCONF_CMD) --libs-only-l $(pc_reqs) $(HIDE_ERR))) \
	$(shell $(SED) -n '/^Libs.private: /s///p' $(LIB_pc))
LDLIBS         ?=
LDLIBS_        := $(DEFAULT_LDLIBS) $(LDLIBS)


endif  # include guard
