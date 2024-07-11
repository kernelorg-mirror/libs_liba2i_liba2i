// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_STRTOI_STRTOI_STRTOI_C_H_
#define LIB_SRC_A2I_STRTOI_STRTOI_STRTOI_C_H_


#include <stdint.h>

#include "lib/src/a2i/attr.h"
#include "lib/src/a2i/qual.h"
#include "lib/src/a2i/strtoi/strtoi/strtoi_nc.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_STRING(1)
inline intmax_t a2i_strtoi_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status);


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
inline intmax_t
a2i_strtoi_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtoi_nc((char *) s, (char **a2i_nullable) endp, base,
	                     min, max, status);
}
#pragma GCC diagnostic pop
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
