// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_A2I_A2U_C_H_
#define LIB_SRC_A2I_A2I_A2U_C_H_


#include "include/a2i/a2i/a2u_c.h"

#include "lib/src/a2i/a2i/a2u.h"
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
a2uhh_c(unsigned char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max)
{
	return a2uhh(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2uh_c(unsigned short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max)
{
	return a2uh(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2ui_c(unsigned int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max)
{
	return a2ui(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2ul_c(unsigned long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max)
{
	return a2ul(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

inline int
a2ull_c(unsigned long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max)
{
	return a2ull(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}
#pragma GCC diagnostic pop  // -Wcast-qual
#if defined(__clang__)
# pragma clang diagnostic pop  // -Wimplicit-int-conversion, -Wshorten-64-to-32
# pragma clang assume_nonnull end
#endif


#endif  // include guard
