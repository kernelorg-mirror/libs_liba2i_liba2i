// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/str2i.h>


#pragma clang assume_nonnull begin
extern inline int str2shh(signed char *restrict n, const char *restrict s);
extern inline int str2sh(short *restrict n, const char *restrict s);
extern inline int str2si(int *restrict n, const char *restrict s);
extern inline int str2sl(long *restrict n, const char *restrict s);
extern inline int str2sll(long long *restrict n, const char *restrict s);

extern inline int str2uhh(unsigned char *restrict n, const char *restrict s);
extern inline int str2uh(unsigned short *restrict n, const char *restrict s);
extern inline int str2ui(unsigned int *restrict n, const char *restrict s);
extern inline int str2ul(unsigned long *restrict n, const char *restrict s);
extern inline int str2ull(unsigned long long *restrict n,
    const char *restrict s);
#pragma clang assume_nonnull end
