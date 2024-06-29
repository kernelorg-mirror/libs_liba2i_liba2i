// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/strtoi/strtou_noneg.h>

#include <errno.h>
#include <stddef.h>
#include <stdint.h>

#include <a2i/qual.h>
#include <a2i/strtoi/strtoi.h>
#include <a2i/strtoi/strtou.h>


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
uintmax_t
a2i_strtou_noneg_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtou_noneg((char *) s, (char **a2i_nullable) endp, base,
	                        min, max, status);
}
#pragma GCC diagnostic pop


uintmax_t
a2i_strtou_noneg_nc(char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	int  st;

	if (status == NULL)
		status = &st;
	if (a2i_strtoi(s, endp, base, 0, 1, status) == 0 && *status == ERANGE)
		return min;

	return a2i_strtou(s, endp, base, min, max, status);
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
