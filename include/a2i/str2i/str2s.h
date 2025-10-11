// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_STR2S_H_
#define INCLUDE_A2I_STR2I_STR2S_H_


#include <limits.h>
#include <stddef.h>

#include <a2i/a2i/a2s.h>
#include <a2i/attr.h>
#include <a2i/inline.h>


#define A2I_STR2S_ATTR                                                        \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_NONNULL(1, 2)                                                \
	A2I_ATTR_STRING(2)                                                    \
	A2I_ATTR_LEAF                                                         \
	A2I_ATTR_NOTHROW


A2I_STR2S_ATTR
a2i_inline int str2shh(signed char *restrict n, const char *restrict s);

A2I_STR2S_ATTR
a2i_inline int str2sh(short *restrict n, const char *restrict s);

A2I_STR2S_ATTR
a2i_inline int str2si(int *restrict n, const char *restrict s);

A2I_STR2S_ATTR
a2i_inline int str2sl(long *restrict n, const char *restrict s);

A2I_STR2S_ATTR
a2i_inline int str2sll(long long *restrict n, const char *restrict s);


#if defined(A2I_INTERNAL)
inline int
str2shh(signed char *restrict n, const char *restrict s)
{
	return a2shh(n, s, NULL, 0, SCHAR_MIN, SCHAR_MAX);
}

inline int
str2sh(short *restrict n, const char *restrict s)
{
	return a2sh(n, s, NULL, 0, SHRT_MIN, SHRT_MAX);
}

inline int
str2si(int *restrict n, const char *restrict s)
{
	return a2si(n, s, NULL, 0, INT_MIN, INT_MAX);
}

inline int
str2sl(long *restrict n, const char *restrict s)
{
	return a2sl(n, s, NULL, 0, LONG_MIN, LONG_MAX);
}

inline int
str2sll(long long *restrict n, const char *restrict s)
{
	return a2sll(n, s, NULL, 0, LLONG_MIN, LLONG_MAX);
}
#endif  // defined(A2I_INTERNAL)


#endif  // include guard
