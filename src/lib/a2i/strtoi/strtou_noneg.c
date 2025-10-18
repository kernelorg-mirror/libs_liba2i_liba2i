// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#define A2I_INTERNAL
#include "include/a2i/strtoi/strtou_noneg.h"

#include <stdint.h>


extern inline uintmax_t a2i_strtou_noneg(const char *restrict s,
    char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status);
