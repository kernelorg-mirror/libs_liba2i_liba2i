// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/a2i_func.h>

#include <a2i/qual.h>


#pragma clang assume_nonnull begin
extern inline int a2shh_c(signed char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
extern inline int a2sh_c(short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    short min, short max);
extern inline int a2si_c(int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    int min, int max);
extern inline int a2sl_c(long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long min, long max);
extern inline int a2sll_c(long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long long min, long long max);

extern inline int a2uhh_c(unsigned char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
extern inline int a2uh_c(unsigned short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
extern inline int a2ui_c(unsigned int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
extern inline int a2ul_c(unsigned long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
extern inline int a2ull_c(unsigned long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);


extern inline int a2shh_nc(signed char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
extern inline int a2sh_nc(short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max);
extern inline int a2si_nc(int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max);
extern inline int a2sl_nc(long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max);
extern inline int a2sll_nc(long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max);

extern inline int a2uhh_nc(unsigned char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
extern inline int a2uh_nc(unsigned short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
extern inline int a2ui_nc(unsigned int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
extern inline int a2ul_nc(unsigned long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
extern inline int a2ull_nc(unsigned long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);
#pragma clang assume_nonnull end
