#!/usr/bin/bash
# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-or-later WITH LGPL-3.0-linking-exception


set -Eeuf;


out="$(mktemp)";
CFLAGS="$CFLAGS -Werror";
CFLAGS="$CFLAGS $(pkgconf --cflags liba2i)";
LIBS="$(pkgconf --libs liba2i)";


cc $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
| if ! grep -- '-Werror=pointer-sign' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [-Werror=pointer-sign]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i.h>

	int
	main(void)
	{
		signed char  n;

		str2u(unsigned char, &n, "0");
	}
__EOF__


cc $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
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

		str2u(unsigned int, &n, "0");
	}
__EOF__


cc $CFLAGS -o "$out" -x c - $LIBS 2>&1 <<__EOF__ \
| if ! grep -- 'static assertion failed' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected static assertion failed"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i.h>

	int
	main(void)
	{
		long  n;

		str2u(long, &n, "0");
	}
__EOF__
