// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/str2i/str2u.h>

#include <limits.h>
#include <stddef.h>

#include <a2i/a2i/a2u.h>


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
int
str2uhh(unsigned char *restrict n, const char *s)
{
	return a2uhh(n, s, NULL, 0, 0, UCHAR_MAX);
}

int
str2uh(unsigned short *restrict n, const char *s)
{
	return a2uh(n, s, NULL, 0, 0, USHRT_MAX);
}

int
str2ui(unsigned int *restrict n, const char *s)
{
	return a2ui(n, s, NULL, 0, 0, UINT_MAX);
}

int
str2ul(unsigned long *restrict n, const char *s)
{
	return a2ul(n, s, NULL, 0, 0, ULONG_MAX);
}

int
str2ull(unsigned long long *restrict n, const char *s)
{
	return a2ull(n, s, NULL, 0, 0, ULLONG_MAX);
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
