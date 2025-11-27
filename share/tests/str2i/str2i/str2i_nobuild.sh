#!/usr/bin/env bash
# Copyright 2024 Alejandro Colomar <alx@kernel.org>
# SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


set -Eeuf;


out="$(mktemp)";


$CC $CFLAGS_ -o "$out" -x c - $LDLIBS_ 2>&1 <<__EOF__ \
| if ! grep -- 'pointer-sign' >/dev/null; then \
	>&2 printf '%s\n' "$0:$LINENO: Expected error: [pointer-sign]"; \
	exit 1; \
else \
	true; \
fi;
	#include <a2i.h>

	int
	main(void)
	{
		unsigned char  n;

		str2i(signed char, &n, "0");
	}
__EOF__
