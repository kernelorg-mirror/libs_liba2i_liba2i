#!/usr/bin/bash
# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-or-later WITH LGPL-3.0-linking-exception


set -Eeuf;


out="$(mktemp)";
CFLAGS="$CFLAGS -Werror";
CFLAGS="$CFLAGS $(pkgconf --cflags liba2i)";
LIBS="$(pkgconf --libs liba2i)";


$CC $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
| if ! grep -- '-Werror=pointer-sign' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [-Werror=pointer-sign]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/a2i.h>

	int
	main(void)
	{
		unsigned int  n;

		a2si(&n, "0", NULL, 0, 0, 0);
	}
__EOF__


$CC $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
| if ! grep -- 'incompatible-pointer-types' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [incompatible-pointer-types]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/a2i.h>

	int
	main(void)
	{
		long  n;

		a2si(&n, "0", NULL, 0, 0, 0);
	}
__EOF__
