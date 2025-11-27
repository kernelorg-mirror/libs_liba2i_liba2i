// SPDX-FileCopyrightText: 2023-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STRTOI_STRTOI_H_
#define INCLUDE_A2I_STRTOI_STRTOI_H_


#include <stdint.h>

#include <a2i/attr.h>


A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_NONNULL(1)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
intmax_t a2i_strtoi2(const char *restrict s,
    char **restrict endp, int base,
    intmax_t min, intmax_t max, int *restrict status);


#endif  // include guard
