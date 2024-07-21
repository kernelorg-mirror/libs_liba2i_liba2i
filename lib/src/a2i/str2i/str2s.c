// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#define A2I_INTERNAL
#include "lib/src/a2i/str2i/str2s.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
extern inline int str2shh(signed char *restrict n, const char *restrict s);
extern inline int str2sh(short *restrict n, const char *restrict s);
extern inline int str2si(int *restrict n, const char *restrict s);
extern inline int str2sl(long *restrict n, const char *restrict s);
extern inline int str2sll(long long *restrict n, const char *restrict s);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
