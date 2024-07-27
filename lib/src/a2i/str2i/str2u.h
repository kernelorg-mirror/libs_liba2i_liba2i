// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_STR2I_STR2U_H_
#define LIB_SRC_A2I_STR2I_STR2U_H_


#include "include/a2i/str2i/str2u.h"

#include <limits.h>
#include <stddef.h>

#include "lib/src/a2i/a2i/a2u.h"


inline int
str2uhh(unsigned char *restrict n, const char *restrict s)
{
	return a2uhh(n, s, NULL, 0, 0, UCHAR_MAX);
}

inline int
str2uh(unsigned short *restrict n, const char *restrict s)
{
	return a2uh(n, s, NULL, 0, 0, USHRT_MAX);
}

inline int
str2ui(unsigned int *restrict n, const char *restrict s)
{
	return a2ui(n, s, NULL, 0, 0, UINT_MAX);
}

inline int
str2ul(unsigned long *restrict n, const char *restrict s)
{
	return a2ul(n, s, NULL, 0, 0, ULONG_MAX);
}

inline int
str2ull(unsigned long long *restrict n, const char *restrict s)
{
	return a2ull(n, s, NULL, 0, 0, ULLONG_MAX);
}


#endif  // include guard
