// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_A2I_A2S_NC_H_
#define LIB_SRC_A2I_A2I_A2S_NC_H_


#include "include/a2i/a2i/a2s_nc.h"

#include <errno.h>

#include "lib/src/a2i/qual.h"
#include "lib/src/a2i/strtoi/strtoi/strtoi.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wimplicit-int-conversion"
# pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif
inline int
a2shh_nc(signed char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2sh_nc(short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2si_nc(int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2sl_nc(long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max)
{
	int  status;

	*n = a2i_strtoi(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2sll_nc(long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
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
# pragma clang assume_nonnull end
#endif


#endif  // include guard
