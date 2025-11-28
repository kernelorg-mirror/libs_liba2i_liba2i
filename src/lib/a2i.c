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


#define ISSPACE(c)  isspace((unsigned char) ({(char){c};}))
#define ISALNUM(c)  isalnum((unsigned char) ({(char){c};}))
#define streq(a,b)  (strcmp(a,b) == 0)


intmax_t
atosimax(const char *restrict s, char **restrict endp, int base,
    intmax_t min, intmax_t max, int *restrict status)
{
	int        errno_saved;
	intmax_t   n;

	endp = endp ?: &(char *){NULL};
	status = status ?: &(int){0};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
	*endp = (char *) s;
#pragma GCC diagnostic pop

	n = 0;
	if (base < 0 || base == 1 || base > 36) {
		*status = EINVAL;
		goto clamp;
	}
	if (ISSPACE(*s)) {
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
	else if (!streq(*endp, ""))
		*status = ENOTSUP;
	else
		*status = 0;

	errno = errno_saved;
clamp:
	return MAX(min, MIN(max, n));
}


uintmax_t
atouimax(const char *restrict s, char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status)
{
	int        errno_saved;
	uintmax_t  n;

	endp = endp ?: &(char *){NULL};
	status = status ?: &(int){0};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
	*endp = (char *) s;
#pragma GCC diagnostic pop

	n = 0;
	if (base < 0 || base == 1 || base > 36) {
		*status = EINVAL;
		goto clamp;
	}
	if (ISSPACE(*s)) {
		*status = ECANCELED;
		goto clamp;
	}
	if (!ISALNUM(*s)) {
		*status = ECANCELED;
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
	else if (!streq(*endp, ""))
		*status = ENOTSUP;
	else
		*status = 0;

	errno = errno_saved;
clamp:
	return MAX(min, MIN(max, n));
}
