// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/a2i_func.h>

#include <a2i/qual.h>


#pragma clang assume_nonnull begin
extern inline int a2shh(signed char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
extern inline int a2sh(short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max);
extern inline int a2si(int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max);
extern inline int a2sl(long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max);
extern inline int a2sll(long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max);

extern inline int a2uhh(unsigned char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
extern inline int a2uh(unsigned short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
extern inline int a2ui(unsigned int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
extern inline int a2ul(unsigned long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
extern inline int a2ull(unsigned long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);
#pragma clang assume_nonnull end
