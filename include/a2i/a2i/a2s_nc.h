// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2S_NC_H_
#define INCLUDE_A2I_A2I_A2S_NC_H_


#include <a2i/attr.h>
#include <a2i/qual.h>


#define A2I_A2S_NC_ATTR                                                       \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_STRING(2)                                                    \


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_A2S_NC_ATTR
int a2shh_nc(signed char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
A2I_A2S_NC_ATTR
int a2sh_nc(short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max);
A2I_A2S_NC_ATTR
int a2si_nc(int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max);
A2I_A2S_NC_ATTR
int a2sl_nc(long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max);
A2I_A2S_NC_ATTR
int a2sll_nc(long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
