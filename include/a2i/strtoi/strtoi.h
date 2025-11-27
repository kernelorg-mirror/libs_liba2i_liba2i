// SPDX-FileCopyrightText: 2023-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STRTOI_STRTOI_H_
#define INCLUDE_A2I_STRTOI_STRTOI_H_


#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/param.h>

#include <a2i/attr.h>
#include <a2i/inline.h>


#ifndef A2I_ISSPACE
#define A2I_ISSPACE(c)  isspace(({(unsigned char){c};}))
#endif


A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_NONNULL(1)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
a2i_inline intmax_t a2i_strtoi2(const char *restrict s,
    char **restrict endp, int base,
    intmax_t min, intmax_t max, int *restrict status);


#if defined(A2I_INTERNAL)
inline intmax_t
a2i_strtoi2(const char *restrict s,
    char **restrict endp, int base,
    intmax_t min, intmax_t max, int *restrict status)
{
	int        errno_saved;
	intmax_t   n;

	if (endp == NULL)
		endp = &(char *){};

	*endp = (char *) s;

	n = 0;
	if (base < 0 || base == 1 || base > 36) {
		*status = EINVAL;
		goto clamp;
	}
	if (A2I_ISSPACE(*s)) {
		*status = ECANCELED;
		goto clamp;
	}

	errno_saved = errno;
	errno = 0;

	n = strtoimax(s, endp, base);

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
#endif  // defined(A2I_INTERNAL)


#endif  // include guard
