// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#define A2I_INTERNAL
#include "lib/src/a2i/a2i/a2s_.h"

#include "lib/src/a2i/attr.h"


extern inline int a2shh_nc(signed char *restrict n, char *restrict s,
    char **restrict endp, int base,
    signed char min, signed char max);

extern inline int a2sh_nc(short *restrict n, char *restrict s,
    char **restrict endp, int base,
    short min, short max);

extern inline int a2si_nc(int *restrict n, char *restrict s,
    char **restrict endp, int base,
    int min, int max);

extern inline int a2sl_nc(long *restrict n, char *restrict s,
    char **restrict endp, int base,
    long min, long max);

extern inline int a2sll_nc(long long *restrict n, char *restrict s,
    char **restrict endp, int base,
    long long min, long long max);


A2I_ATTR_ALIAS("a2shh_nc")
int a2shh_c(signed char *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    signed char min, signed char max);

A2I_ATTR_ALIAS("a2sh_nc")
int a2sh_c(short *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    short min, short max);

A2I_ATTR_ALIAS("a2si_nc")
int a2si_c(int *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    int min, int max);

A2I_ATTR_ALIAS("a2sl_nc")
int a2sl_c(long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    long min, long max);

A2I_ATTR_ALIAS("a2sll_nc")
int a2sll_c(long long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    long long min, long long max);
