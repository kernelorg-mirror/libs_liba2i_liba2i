// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include "lib/src/a2i/strtoi/strtou/strtou.h"

#include <stdint.h>

#include "lib/src/a2i/qual.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
extern inline uintmax_t
a2i_strtou(char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
