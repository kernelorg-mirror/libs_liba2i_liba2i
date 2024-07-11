// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STRTOI_STRTOI_STRTOI_C_H_
#define INCLUDE_A2I_STRTOI_STRTOI_STRTOI_C_H_


#include <stdint.h>

#include <a2i/attr.h>
#include <a2i/inline.h>
#include <a2i/qual.h>


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_STRING(1)
a2i_inline
intmax_t a2i_strtoi_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
