// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_STRTOI_STRTOU_NONEG_STRTOU_NONEG_NC_H_
#define LIB_SRC_A2I_STRTOI_STRTOU_NONEG_STRTOU_NONEG_NC_H_


#include "include/a2i/strtoi/strtou_noneg/strtou_noneg_nc.h"

#include <errno.h>
#include <stddef.h>
#include <stdint.h>

#include "lib/src/a2i/qual.h"
#include "lib/src/a2i/strtoi/strtoi/strtoi.h"
#include "lib/src/a2i/strtoi/strtou/strtou.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
inline uintmax_t
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


#endif  // include guard
