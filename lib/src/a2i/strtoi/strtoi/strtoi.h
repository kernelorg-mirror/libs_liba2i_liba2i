// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_STRTOI_STRTOI_STRTOI_H_
#define LIB_SRC_A2I_STRTOI_STRTOI_STRTOI_H_


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
A2I_ATTR_NONNULL(1)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
A2I_ATTR_VISIBILITY("internal")
inline intmax_t a2i_strtoi(char *s,
    char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status);


inline intmax_t
a2i_strtoi(char *s,
    char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status)
{
	int        errno_saved, st;
	char       *e;
	intmax_t   n;

	errno_saved = errno;
	errno = 0;

	e = NULL;

	n = strtoimax(s, &e, base);

	if (e == NULL)
		st = errno;
	else if (e == s)
		st = ECANCELED;
	else if (errno == ERANGE || n < min || n > max)
		st = ERANGE;
	else if (*e != '\0')
		st = ENOTSUP;
	else
		st = 0;

	if (status != NULL)
		*status = st;
	if (endp != NULL && e != NULL)
		*endp = e;

	errno = errno_saved;

	return MAX(min, MIN(max, n));
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
