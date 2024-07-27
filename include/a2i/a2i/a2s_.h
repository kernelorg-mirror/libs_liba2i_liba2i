// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2S__H_
#define INCLUDE_A2I_A2I_A2S__H_


#include <a2i/attr.h>
#include <a2i/inline.h>


#define A2I_A2S_ATTR                                                          \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_NONNULL(1, 2)                                                \
	A2I_ATTR_STRING(2)                                                    \
	A2I_ATTR_LEAF                                                         \
	A2I_ATTR_NOTHROW


A2I_A2S_ATTR
a2i_inline
int a2shh_nc(signed char *restrict n, char *restrict s,
    char **restrict endp, int base,
    signed char min, signed char max);

A2I_A2S_ATTR
a2i_inline
int a2sh_nc(short *restrict n, char *restrict s,
    char **restrict endp, int base,
    short min, short max);

A2I_A2S_ATTR
a2i_inline
int a2si_nc(int *restrict n, char *restrict s,
    char **restrict endp, int base,
    int min, int max);

A2I_A2S_ATTR
a2i_inline
int a2sl_nc(long *restrict n, char *restrict s,
    char **restrict endp, int base,
    long min, long max);

A2I_A2S_ATTR
a2i_inline
int a2sll_nc(long long *restrict n, char *restrict s,
    char **restrict endp, int base,
    long long min, long long max);


A2I_A2S_ATTR
int a2shh_c(signed char *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    signed char min, signed char max);

A2I_A2S_ATTR
int a2sh_c(short *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    short min, short max);

A2I_A2S_ATTR
int a2si_c(int *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    int min, int max);

A2I_A2S_ATTR
int a2sl_c(long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    long min, long max);

A2I_A2S_ATTR
int a2sll_c(long long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    long long min, long long max);


#endif  // include guard
