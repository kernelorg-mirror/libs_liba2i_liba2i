#!/usr/bin/env bash
# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-or-later WITH LGPL-3.0-linking-exception


set -Eeuf;


out="$(mktemp)";
CFLAGS="$CFLAGS -Werror";
CFLAGS="$CFLAGS $(pkgconf --cflags liba2i)";
LIBS="$(pkgconf --libs liba2i)";


$CC $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
| if ! grep -- 'pointer-sign' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected error: [pointer-sign]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i.h>

	int
	main(void)
	{
		unsigned char  n;

		str2i(signed char, &n, "0");
	}
__EOF__


$CC $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
| if ! grep -- 'incompatible-pointer-types' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [incompatible-pointer-types]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i.h>

	int
	main(void)
	{
		unsigned long  n;

		str2s(unsigned int, &n, "0");
	}
__EOF__


$CC $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
| if ! grep -- '_Generic' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected error: [_Generic]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i.h>

	int
	main(void)
	{
		float  n;

		str2i(float, &n, "0");
	}
__EOF__
