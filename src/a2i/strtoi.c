// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/strtoi.h>

#include <stdint.h>

#include <a2i/qual.h>


#pragma clang assume_nonnull begin
extern inline intmax_t a2i_strtoi(const char *s,
    char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status);
extern inline uintmax_t a2i_strtou(const char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status);
extern inline uintmax_t a2i_strtou_noneg(const char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status);
#pragma clang assume_nonnull end
