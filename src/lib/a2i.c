// SPDX-FileCopyrightText: 2023-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include "include/a2i.h"

#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/param.h>


#define is_unsigned(T)  (a2i_minof(T) == 0)
#define ISSPACE(c)  isspace((unsigned char) (char){c})
#define ISALNUM(c)  isalnum((unsigned char) (char){c})
#define streq(a,b)  (strcmp(a,b) == 0)


#define ato_imax(T, s, endp, base, min, max, status)                  \
({                                                                    \
	__label__  clamp;                                             \
	int        errno_saved;                                       \
	T          n;                                                 \
                                                                      \
	endp = endp ?: &(char *){NULL};                               \
	status = status ?: &(int){0};                                 \
                                                                      \
	_Pragma("GCC diagnostic push");                               \
	_Pragma("GCC diagnostic ignored \"-Wcast-qual\"");            \
	*endp = (char *) s;                                           \
	_Pragma("GCC diagnostic pop");                                \
                                                                      \
	n = 0;                                                        \
	if (base < 0 || base == 1 || base > 36) {                     \
		*status = EINVAL;                                     \
		goto clamp;                                           \
	}                                                             \
	if (ISSPACE(*s)) {                                            \
		*status = ECANCELED;                                  \
		goto clamp;                                           \
	}                                                             \
	if (is_unsigned(T) && !ISALNUM(*s)) {                         \
		*status = ECANCELED;                                  \
		goto clamp;                                           \
	}                                                             \
                                                                      \
	errno_saved = errno;                                          \
	errno = 0;                                                    \
                                                                      \
	n = _Generic((T){0},                                          \
		intmax_t:  strtoimax,                                 \
		uintmax_t: strtoumax                                  \
	)(s, endp, base);                                             \
                                                                      \
	if (errno != 0 && errno != EINVAL)                            \
		*status = errno;                                      \
	else if (*endp == s)                                          \
		*status = ECANCELED;                                  \
	else if (n < min || n > max)                                  \
		*status = ERANGE;                                     \
	else if (!streq(*endp, ""))                                   \
		*status = ENOTSUP;                                    \
	else                                                          \
		*status = 0;                                          \
                                                                      \
	errno = errno_saved;                                          \
clamp:                                                                \
	MAX(min, MIN(max, n));                                        \
})


intmax_t
atosimax(const char *restrict s, char **restrict endp, int base,
    intmax_t min, intmax_t max, int *restrict status)
{
	return ato_imax(intmax_t, s, endp, base, min, max, status);
}


uintmax_t
atouimax(const char *restrict s, char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status)
{
	return ato_imax(uintmax_t, s, endp, base, min, max, status);
}
