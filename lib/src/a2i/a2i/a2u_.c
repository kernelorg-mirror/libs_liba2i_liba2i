// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#define A2I_INTERNAL
#include "lib/src/a2i/a2i/a2u_.h"

#include "lib/src/a2i/attr.h"


extern inline int a2uhh_nc(unsigned char *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned char min, unsigned char max);

extern inline int a2uh_nc(unsigned short *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned short min, unsigned short max);

extern inline int a2ui_nc(unsigned int *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned int min, unsigned int max);

extern inline int a2ul_nc(unsigned long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long min, unsigned long max);

extern inline int a2ull_nc(unsigned long long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long long min, unsigned long long max);


A2I_ATTR_ALIAS("a2uhh_nc")
int a2uhh_c(unsigned char *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned char min, unsigned char max);

A2I_ATTR_ALIAS("a2uh_nc")
int a2uh_c(unsigned short *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned short min, unsigned short max);

A2I_ATTR_ALIAS("a2ui_nc")
int a2ui_c(unsigned int *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned int min, unsigned int max);

A2I_ATTR_ALIAS("a2ul_nc")
int a2ul_c(unsigned long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned long min, unsigned long max);

A2I_ATTR_ALIAS("a2ull_nc")
int a2ull_c(unsigned long long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned long long min, unsigned long long max);
