// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include "lib/src/a2i/a2i/a2s_nc.h"

#include "lib/src/a2i/qual.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
extern inline int a2shh_nc(signed char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);

extern inline int a2sh_nc(short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max);

extern inline int a2si_nc(int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max);

extern inline int a2sl_nc(long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max);

extern inline int a2sll_nc(long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
