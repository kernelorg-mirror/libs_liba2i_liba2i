// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/str2i.h>

#include <limits.h>
#include <stddef.h>

#include <a2i/a2i.h>


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
int
str2shh(signed char *restrict n, const char *restrict s)
{
	return a2i(signed char, n, s, NULL, 0, SCHAR_MIN, SCHAR_MAX);
}

int
str2sh(short *restrict n, const char *restrict s)
{
	return a2i(short, n, s, NULL, 0, SHRT_MIN, SHRT_MAX);
}

int
str2si(int *restrict n, const char *restrict s)
{
	return a2i(int, n, s, NULL, 0, INT_MIN, INT_MAX);
}

int
str2sl(long *restrict n, const char *restrict s)
{
	return a2i(long, n, s, NULL, 0, LONG_MIN, LONG_MAX);
}

int
str2sll(long long *restrict n, const char *restrict s)
{
	return a2i(long long, n, s, NULL, 0, LLONG_MIN, LLONG_MAX);
}


int
str2uhh(unsigned char *restrict n, const char *restrict s)
{
	return a2i(unsigned char, n, s, NULL, 0, 0, UCHAR_MAX);
}

int
str2uh(unsigned short *restrict n, const char *restrict s)
{
	return a2i(unsigned short, n, s, NULL, 0, 0, USHRT_MAX);
}

int
str2ui(unsigned int *restrict n, const char *restrict s)
{
	return a2i(unsigned int, n, s, NULL, 0, 0, UINT_MAX);
}

int
str2ul(unsigned long *restrict n, const char *restrict s)
{
	return a2i(unsigned long, n, s, NULL, 0, 0, ULONG_MAX);
}

int
str2ull(unsigned long long *restrict n, const char *restrict s)
{
	return a2i(unsigned long long, n, s, NULL, 0, 0, ULLONG_MAX);
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
