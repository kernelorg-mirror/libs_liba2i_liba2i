// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STRTOI_STRTOU_STRTOU_H_
#define INCLUDE_A2I_STRTOI_STRTOU_STRTOU_H_


#include <errno.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/param.h>

#include <a2i/attr.h>


A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_NONNULL(1)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
A2I_ATTR_VISIBILITY("internal")
inline uintmax_t a2i_strtou(char *restrict s,
    char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status);


inline uintmax_t
a2i_strtou(char *restrict s,
    char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status)
{
	int        errno_saved, st;
	char       *e;
	uintmax_t  n;

	if (status == NULL)
		status = &st;
	if (endp == NULL)
		endp = &e;

	*endp = (char *) s;

	if (base < 0 || base == 1 || base > 36) {
		n = 0;
		*status = EINVAL;
		goto clamp;
	}

	errno_saved = errno;
	errno = 0;

	n = strtoumax(s, endp, base);

	if (errno != 0 && errno != EINVAL)
		*status = errno;
	else if (*endp == s)
		*status = ECANCELED;
	else if (n < min || n > max)
		*status = ERANGE;
	else if (strcmp(*endp, "") != 0)
		*status = ENOTSUP;
	else
		*status = 0;

	errno = errno_saved;
clamp:
	return MAX(min, MIN(max, n));
}


#endif  // include guard
