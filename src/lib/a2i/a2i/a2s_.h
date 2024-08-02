// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef SRC_LIB_A2I_A2I_A2S__H_
#define SRC_LIB_A2I_A2I_A2S__H_


#include "include/a2i/a2i/a2s_.h"  // IWYU pragma: export
// IWYU pragma: no_include "a2i/a2i/a2s_.h"

#include <errno.h>

#include "src/lib/a2i/strtoi/strtoi/strtoi.h"


#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wimplicit-int-conversion"
# pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif
inline int
a2shh_nc(signed char *restrict n, char *restrict s,
    char **restrict endp, int base,
    signed char min, signed char max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2sh_nc(short *restrict n, char *restrict s,
    char **restrict endp, int base,
    short min, short max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2si_nc(int *restrict n, char *restrict s,
    char **restrict endp, int base,
    int min, int max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2sl_nc(long *restrict n, char *restrict s,
    char **restrict endp, int base,
    long min, long max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2sll_nc(long long *restrict n, char *restrict s,
    char **restrict endp, int base,
    long long min, long long max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}
#if defined(__clang__)
# pragma clang diagnostic pop  // -Wimplicit-int-conversion, -Wshorten-64-to-32
#endif


#endif  // include guard
