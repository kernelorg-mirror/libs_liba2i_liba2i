# Copyright 2022-2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


ifndef MAKEFILE_CONFIGURE_COREUTILS_INCLUDED
MAKEFILE_CONFIGURE_COREUTILS_INCLUDED := 1


CP      := cp
CUT     := cut
ECHO    := echo
INSTALL := install
LN      := ln
RM      := rm
SORT    := sort
TAC     := tac
TOUCH   := touch


INSTALL_DATA    := $(INSTALL) -m 644
INSTALL_DIR     := $(INSTALL) -m 755 -d
INSTALL_PROGRAM := $(INSTALL) -m 755


endif  # include guard
