// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_A2I_A2S_C_H_
#define LIB_SRC_A2I_A2I_A2S_C_H_


#include "include/a2i/a2i/a2s_c.h"

#include "lib/src/a2i/a2i/a2s.h"
#include "lib/src/a2i/qual.h"


#if defined(__clang__)
# pragma clang assume_nonnull begin
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wimplicit-int-conversion"
# pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
inline int
a2shh_c(signed char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    signed char min, signed char max)
{
	return a2shh(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2sh_c(short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    short min, short max)
{
	return a2sh(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2si_c(int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    int min, int max)
{
	return a2si(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2sl_c(long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long min, long max)
{
	return a2sl(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2sll_c(long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long long min, long long max)
{
	return a2sll(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}
#pragma GCC diagnostic pop  // -Wcast-qual
#if defined(__clang__)
# pragma clang diagnostic pop  // -Wimplicit-int-conversion, -Wshorten-64-to-32
# pragma clang assume_nonnull end
#endif


#endif  // include guard
