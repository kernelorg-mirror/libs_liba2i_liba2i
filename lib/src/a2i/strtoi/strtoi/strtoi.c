// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#define A2I_INTERNAL
#include "lib/src/a2i/strtoi/strtoi/strtoi.h"

#include <stdint.h>

#include "lib/src/a2i/qual.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
extern inline intmax_t a2i_strtoi(char *restrict s,
    char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
