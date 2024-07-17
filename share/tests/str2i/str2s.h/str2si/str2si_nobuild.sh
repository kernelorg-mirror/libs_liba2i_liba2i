#!/usr/bin/env bash
# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


set -Eeuf;


out="$(mktemp)";


$CC $CFLAGS_ -o "$out" -x c - $LDLIBS_ 2>&1 <<__EOF__ \
| if ! grep -- 'pointer-sign' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [pointer-sign]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i/str2s.h>

	int
	main(void)
	{
		unsigned int  n;

		str2si(&n, "0");
	}
__EOF__


$CC $CFLAGS_ -o "$out" -x c - $LDLIBS_ 2>&1 <<__EOF__ \
| if ! grep -- 'incompatible-pointer-types' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected [incompatible-pointer-types]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i/str2i/str2s.h>

	int
	main(void)
	{
		long  n;

		str2si(&n, "0");
	}
__EOF__
