// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/a2i/a2s.h>

#include <errno.h>

#include <a2i/qual.h>
#include <a2i/strtoi/strtoi.h>


#define a2i_a2S_nc(n, ...)                                                    \
({                                                                            \
	int  status_;                                                         \
                                                                              \
	*n = _Generic(*n,                                                     \
		signed char:         a2i_strtoi,                              \
		short:               a2i_strtoi,                              \
		int:                 a2i_strtoi,                              \
		long:                a2i_strtoi,                              \
		long long:           a2i_strtoi                               \
	)(__VA_ARGS__, &status_);                                             \
	if (status_ != 0)                                                     \
		errno = status_;                                              \
                                                                              \
	-!!status_;                                                           \
})


#if defined(__clang__)
# pragma clang assume_nonnull begin
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wimplicit-int-conversion"
# pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
int
a2shh_c(signed char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    signed char min, signed char max)
{
	return a2shh(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

int
a2sh_c(short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    short min, short max)
{
	return a2sh(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

int
a2si_c(int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    int min, int max)
{
	return a2si(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

int
a2sl_c(long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long min, long max)
{
	return a2sl(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}

int
a2sll_c(long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long long min, long long max)
{
	return a2sll(n, (char *) s, (char **a2i_nullable) endp, base, min, max);
}
#pragma GCC diagnostic pop  // -Wcast-qual


int
(a2shh)(signed char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max)
{
	return a2i_a2S_nc(n, s, endp, base, min, max);
}

int
(a2sh)(short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max)
{
	return a2i_a2S_nc(n, s, endp, base, min, max);
}

int
(a2si)(int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max)
{
	return a2i_a2S_nc(n, s, endp, base, min, max);
}

int
(a2sl)(long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max)
{
	return a2i_a2S_nc(n, s, endp, base, min, max);
}

int
(a2sll)(long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max)
{
	return a2i_a2S_nc(n, s, endp, base, min, max);
}
#if defined(__clang__)
# pragma clang diagnostic pop  // -Wimplicit-int-conversion, -Wshorten-64-to-32
# pragma clang assume_nonnull end
#endif
