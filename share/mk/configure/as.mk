# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_AS_INCLUDED
MAKEFILE_CONFIGURE_AS_INCLUDED := 1


include $(MAKEFILEDIR)/configure/cc.mk
include $(MAKEFILEDIR)/configure/cpp.mk


DEFAULT_ASFLAGS :=
EXTRA_ASFLAGS   :=
ASFLAGS         := $(DEFAULT_ASFLAGS) $(EXTRA_ASFLAGS)
AS              := $(CC) $(CPPFLAGS) $(CFLAGS)


endif  # include guard
