# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_LD_INCLUDED
MAKEFILE_CONFIGURE_LD_INCLUDED := 1


include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/coreutils.mk
include $(MAKEFILEDIR)/configure/pkgconf.mk
include $(MAKEFILEDIR)/configure/sed.mk
include $(MAKEFILEDIR)/verbose.mk
include $(MAKEFILEDIR)/version.mk


LD := $(CC) $(CFLAGS)


LD_HAS_FUSE_LINKER_PLUGIN := \
	$(shell \
		$(ECHO) 'int main(void) {}' \
		| $(LD) -fuse-linker-plugin -x c -o /dev/null /dev/stdin $(HIDE_ERR) \
		&& $(ECHO) yes \
		|| $(ECHO) no; \
	)


DEFAULT_LDFLAGS := -shared
DEFAULT_LDFLAGS += -Wl,-soname,$(libname).so.$(MAJOR_VERSION)
DEFAULT_LDFLAGS += -Wl,--as-needed
DEFAULT_LDFLAGS += -Wl,--no-allow-shlib-undefined
DEFAULT_LDFLAGS += -Wl,--no-copy-dt-needed-entries
DEFAULT_LDFLAGS += -Wl,--no-undefined
DEFAULT_LDFLAGS += $(shell $(PKGCONF_CMD) --libs-only-L $(pc_reqs) $(HIDE_ERR))
DEFAULT_LDFLAGS += $(shell $(PKGCONF_CMD) --libs-only-other $(pc_reqs) $(HIDE_ERR))

ifeq ($(LD_HAS_FUSE_LINKER_PLUGIN),yes)
DEFAULT_LDFLAGS += -fuse-linker-plugin
endif

EXTRA_LDFLAGS   :=
LDFLAGS         := $(DEFAULT_LDFLAGS) $(EXTRA_LDFLAGS)


DEFAULT_LDLIBS := $(filter-out -la2i,$(shell $(PKGCONF_CMD) --libs-only-l $(pc_reqs) $(HIDE_ERR)))
DEFAULT_LDLIBS += $(shell $(SED) -n '/^Libs.private: /s///p' $(LIB_pc_u))
EXTRA_LDLIBS   :=
LDLIBS         := $(DEFAULT_LDLIBS) $(EXTRA_LDLIBS)


endif  # include guard
