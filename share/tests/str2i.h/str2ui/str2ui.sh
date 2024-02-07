#!/bin/sh
# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-or-later WITH LGPL-3.0-linking-exception

out="$(mktemp)";
CFLAGS="$CFLAGS -Werror";
CFLAGS="$CFLAGS $(pkgconf --cflags liba2i)";
LIBS="$(pkgconf --libs liba2i)";

$CC $CFLAGS -o "$out" "$(dirname "$0")"/str2ui.c $LIBS;
"$out";
