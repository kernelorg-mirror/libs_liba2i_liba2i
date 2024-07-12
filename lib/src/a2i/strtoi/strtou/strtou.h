// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_STRTOI_STRTOU_STRTOU_H_
#define LIB_SRC_A2I_STRTOI_STRTOU_STRTOU_H_


#include <errno.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/param.h>

#include "lib/src/a2i/attr.h"
#include "lib/src/a2i/qual.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
inline
uintmax_t a2i_strtou(char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status);


inline uintmax_t
a2i_strtou(char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	int        errno_saved, st;
	char       *e;
	uintmax_t  n;

	if (endp == NULL)
		endp = &e;
	if (status == NULL)
		status = &st;

	if (base != 0 && (base < 2 || base > 36)) {
		*status = EINVAL;
		return MAX(min, 0);
	}

	errno_saved = errno;
	errno = 0;

	n = strtoumax(s, endp, base);

	if (*endp == s)
		*status = ECANCELED;
	else if (errno == ERANGE || n < min || n > max)
		*status = ERANGE;
	else if (**endp != '\0')
		*status = ENOTSUP;
	else
		*status = 0;

	errno = errno_saved;

	return MAX(min, MIN(max, n));
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
