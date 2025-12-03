# Copyright, the authors of liba2i
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_AS_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_BINUTILS_AS_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/gcc/cc.mk
include $(MAKEFILEDIR)/configure/build-depends/cpp/cpp.mk


DEFAULT_ASFLAGS :=
ASFLAGS         :=
ASFLAGS_        := $(DEFAULT_ASFLAGS) $(ASFLAGS)
AS              := $(CC) $(CPPFLAGS_) $(CFLAGS_)


endif  # include guard
