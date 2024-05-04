#!/usr/bin/env bash
# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-or-later WITH LGPL-3.0-linking-exception


set -Eeuf;


out="$(mktemp)";


$CC $CFLAGS -o "$out" -x c - $LDLIBS 2>&1 <<__EOF__ \
| if ! grep -- 'pointer-sign' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [pointer-sign]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i.h>

	int
	main(void)
	{
		unsigned char  n;

		str2shh(&n, "0");
	}
__EOF__


$CC $CFLAGS -o "$out" -x c - $LDLIBS 2>&1 <<__EOF__ \
| if ! grep -- 'pointer-sign' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [pointer-sign]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i.h>

	int
	main(void)
	{
		char  n;

		str2shh(&n, "0");
	}
__EOF__


$CC $CFLAGS -o "$out" -x c - $LDLIBS 2>&1 <<__EOF__ \
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
		long  n;

		str2shh(&n, "0");
	}
__EOF__
