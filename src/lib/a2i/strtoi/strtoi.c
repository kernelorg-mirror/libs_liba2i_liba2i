// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#define A2I_INTERNAL
#include "include/a2i/strtoi/strtoi.h"

#include <stdint.h>


extern inline intmax_t a2i_strtoi(const char *restrict s,
    char **restrict endp, int base,
    intmax_t min, intmax_t max, int *restrict status);
