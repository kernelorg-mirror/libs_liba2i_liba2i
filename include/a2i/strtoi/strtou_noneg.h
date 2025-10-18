// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STRTOI_STRTOU_NONEG_H_
#define INCLUDE_A2I_STRTOI_STRTOU_NONEG_H_


#include <errno.h>
#include <stddef.h>
#include <stdint.h>

#include <a2i/attr.h>
#include <a2i/inline.h>
#include <a2i/strtoi/strtoi.h>
#include <a2i/strtoi/strtou.h>


A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_NONNULL(1)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
a2i_inline uintmax_t a2i_strtou_noneg(const char *restrict s,
    char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status);


#if defined(A2I_INTERNAL)
inline uintmax_t
a2i_strtou_noneg(const char *restrict s,
    char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status)
{
	int  st;

	if (status == NULL)
		status = &st;
	if (a2i_strtoi(s, endp, base, 0, 1, status) == 0 && *status == ERANGE)
		return min;

	return a2i_strtou(s, endp, base, min, max, status);
}
#endif  // defined(A2I_INTERNAL)


#endif  // include guard
