# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_LD_INCLUDED
MAKEFILE_CONFIGURE_LD_INCLUDED := 1


include $(MAKEFILEDIR)/cmd.mk
include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/pkgconf.mk
include $(MAKEFILEDIR)/verbose.mk
include $(MAKEFILEDIR)/version.mk


DEFAULT_LDFLAGS := -shared
DEFAULT_LDFLAGS += -fuse-linker-plugin
DEFAULT_LDFLAGS += -Wl,-soname,$(libname).so.$(MAJOR_VERSION)
DEFAULT_LDFLAGS += -Wl,--as-needed
DEFAULT_LDFLAGS += -Wl,--no-allow-shlib-undefined
DEFAULT_LDFLAGS += -Wl,--no-copy-dt-needed-entries
DEFAULT_LDFLAGS += -Wl,--no-undefined
DEFAULT_LDFLAGS += $(shell $(PKGCONF_CMD) --libs-only-L $(pc_reqs) $(HIDE_ERR))
DEFAULT_LDFLAGS += $(shell $(PKGCONF_CMD) --libs-only-other $(pc_reqs) $(HIDE_ERR))
EXTRA_LDFLAGS   :=
LDFLAGS         := $(DEFAULT_LDFLAGS) $(EXTRA_LDFLAGS)
LD              := $(CC) $(CFLAGS)


DEFAULT_LDLIBS := $(filter-out -la2i,$(shell $(PKGCONF_CMD) --libs-only-l $(pc_reqs) $(HIDE_ERR)))
DEFAULT_LDLIBS += $(shell $(SED) -n '/^Libs.private: /s///p' $(LIB_pc_u))
EXTRA_LDLIBS   :=
LDLIBS         := $(DEFAULT_LDLIBS) $(EXTRA_LDLIBS)


endif  # include guard
