# Copyright 2021-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_SRC_TU_INCLUDED
MAKEFILE_SRC_TU_INCLUDED := 1


include $(MAKEFILEDIR)/configure/build-depends/coreutils/sort.mk
include $(MAKEFILEDIR)/configure/build-depends/findutils/find.mk
include $(MAKEFILEDIR)/configure/build-depends/grep/grep.mk
include $(MAKEFILEDIR)/configure/directory_variables/src.mk


TU_h := $(shell $(FIND) $(INCLUDEDIR) -type f | $(GREP) '\.h$$' | $(SORT))
TU_c := $(shell $(FIND) $(LIBSRCDIR)  -type f | $(GREP) '\.c$$' | $(SORT))


endif  # include guard
