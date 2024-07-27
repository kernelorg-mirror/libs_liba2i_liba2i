// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_A2I_A2U__H_
#define LIB_SRC_A2I_A2I_A2U__H_


#include "include/a2i/a2i/a2u_.h"  // IWYU pragma: export
// IWYU pragma: no_include "a2i/a2i/a2u_.h"

#include <errno.h>

#include "lib/src/a2i/strtoi/strtou_noneg/strtou_noneg.h"


#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wimplicit-int-conversion"
# pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif
inline int
a2uhh_nc(unsigned char *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned char min, unsigned char max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2uh_nc(unsigned short *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned short min, unsigned short max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2ui_nc(unsigned int *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned int min, unsigned int max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2ul_nc(unsigned long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long min, unsigned long max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2ull_nc(unsigned long long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long long min, unsigned long long max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}
#if defined(__clang__)
# pragma clang diagnostic pop  // -Wimplicit-int-conversion, -Wshorten-64-to-32
#endif


#endif  // include guard
