// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_FUNC_H_
#define INCLUDE_A2I_A2I_FUNC_H_


#include <a2i/attr.h>
#include <a2i/qual.h>


#define A2I_A2I_ATTR                                                          \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_STRING(2)                                                    \


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_A2I_ATTR
int a2shh_c(signed char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
A2I_A2I_ATTR
int a2sh_c(short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    short min, short max);
A2I_A2I_ATTR
int a2si_c(int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    int min, int max);
A2I_A2I_ATTR
int a2sl_c(long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long min, long max);
A2I_A2I_ATTR
int a2sll_c(long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long long min, long long max);

A2I_A2I_ATTR
int a2uhh_c(unsigned char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
A2I_A2I_ATTR
int a2uh_c(unsigned short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
A2I_A2I_ATTR
int a2ui_c(unsigned int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
A2I_A2I_ATTR
int a2ul_c(unsigned long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
A2I_A2I_ATTR
int a2ull_c(unsigned long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);


A2I_A2I_ATTR
int a2shh_nc(signed char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
A2I_A2I_ATTR
int a2sh_nc(short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max);
A2I_A2I_ATTR
int a2si_nc(int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max);
A2I_A2I_ATTR
int a2sl_nc(long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max);
A2I_A2I_ATTR
int a2sll_nc(long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max);

A2I_A2I_ATTR
int a2uhh_nc(unsigned char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
A2I_A2I_ATTR
int a2uh_nc(unsigned short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
A2I_A2I_ATTR
int a2ui_nc(unsigned int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
A2I_A2I_ATTR
int a2ul_nc(unsigned long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
A2I_A2I_ATTR
int a2ull_nc(unsigned long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
