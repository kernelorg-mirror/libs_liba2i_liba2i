// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_STRTOI_STRTOU_STRTOU_C_H_
#define LIB_SRC_A2I_STRTOI_STRTOU_STRTOU_C_H_


#include "include/a2i/strtoi/strtou/strtou_c.h"

#include <stdint.h>

#include "lib/src/a2i/qual.h"
#include "lib/src/a2i/strtoi/strtou/strtou.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
inline uintmax_t
a2i_strtou_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtou((char *) s, (char **a2i_nullable) endp, base,
	                  min, max, status);
}
#pragma GCC diagnostic pop
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
