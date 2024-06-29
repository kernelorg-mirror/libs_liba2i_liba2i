// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/str2i/str2s.h>

#include <limits.h>
#include <stddef.h>

#include <a2i/a2i/a2s.h>


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
int
str2shh(signed char *restrict n, const char *s)
{
	return a2shh(n, s, NULL, 0, SCHAR_MIN, SCHAR_MAX);
}

int
str2sh(short *restrict n, const char *s)
{
	return a2sh(n, s, NULL, 0, SHRT_MIN, SHRT_MAX);
}

int
str2si(int *restrict n, const char *s)
{
	return a2si(n, s, NULL, 0, INT_MIN, INT_MAX);
}

int
str2sl(long *restrict n, const char *s)
{
	return a2sl(n, s, NULL, 0, LONG_MIN, LONG_MAX);
}

int
str2sll(long long *restrict n, const char *s)
{
	return a2sll(n, s, NULL, 0, LLONG_MIN, LLONG_MAX);
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
