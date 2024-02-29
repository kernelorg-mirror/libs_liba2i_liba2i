# Copyright 2022-2024, Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_BUILD_DEPENDS_COREUTILS_INCLUDED
MAKEFILE_CONFIGURE_BUILD_DEPENDS_COREUTILS_INCLUDED := 1


CAT      := cat
CP       := cp
CUT      := cut
ECHO     := echo
EXPR     := expr
HEAD     := head
INSTALL  := install
LN       := ln
MKDIR    := mkdir
REALPATH := realpath
RM       := rm
SORT     := sort
STAT     := stat
TAC      := tac
TAIL     := tail
TEST     := test
TOUCH    := touch
TRUE     := true


INSTALL_DATA    := $(INSTALL) -m 644
INSTALL_DIR     := $(INSTALL) -m 755 -d
INSTALL_PROGRAM := $(INSTALL) -m 755


endif  # include guard
