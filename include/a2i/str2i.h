// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_H_
#define INCLUDE_A2I_STR2I_H_


#include <stddef.h>

#include <a2i/a2i.h>
#include <a2i/attr.h>
#include <a2i/inline.h>
#include <a2i/typetraits.h>


#define str2i(TYPE, ...)                                                      \
(                                                                             \
	_Generic((TYPE) 0,                                                    \
		signed char:         str2shh,                                 \
		short:               str2sh,                                  \
		int:                 str2si,                                  \
		long:                str2sl,                                  \
		long long:           str2sll,                                 \
                                                                              \
		unsigned char:       str2uhh,                                 \
		unsigned short:      str2uh,                                  \
		unsigned int:        str2ui,                                  \
		unsigned long:       str2ul,                                  \
		unsigned long long:  str2ull                                  \
	)(__VA_ARGS__)                                                        \
)


#define str2s(TYPE, ...)                                                      \
(                                                                             \
	_Generic((TYPE) 0,                                                    \
		signed char:         str2shh,                                 \
		short:               str2sh,                                  \
		int:                 str2si,                                  \
		long:                str2sl,                                  \
		long long:           str2sll                                  \
	)(__VA_ARGS__)                                                        \
)


#define str2u(TYPE, ...)                                                      \
(                                                                            \
	_Generic((TYPE) 0,                                                    \
		unsigned char:       str2uhh,                                 \
		unsigned short:      str2uh,                                  \
		unsigned int:        str2ui,                                  \
		unsigned long:       str2ul,                                  \
		unsigned long long:  str2ull                                  \
	)(__VA_ARGS__)                                                        \
)


#define a2i_str2I(n, s)                                                       \
(                                                                             \
	a2i(typeof(*n), n, s, NULL, 0, a2i_typeof_min(*n), a2i_typeof_max(*n))\
)


#define A2I_STR2I_PROTOTYPE(name, TYPE)                                       \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_STRING(2)                                                    \
	a2i_inline int name(TYPE *restrict n, const char *s)


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_STR2I_PROTOTYPE(str2shh, signed char);
A2I_STR2I_PROTOTYPE(str2sh, short);
A2I_STR2I_PROTOTYPE(str2si, int);
A2I_STR2I_PROTOTYPE(str2sl, long);
A2I_STR2I_PROTOTYPE(str2sll, long long);

A2I_STR2I_PROTOTYPE(str2uhh, unsigned char);
A2I_STR2I_PROTOTYPE(str2uh, unsigned short);
A2I_STR2I_PROTOTYPE(str2ui, unsigned int);
A2I_STR2I_PROTOTYPE(str2ul, unsigned long);
A2I_STR2I_PROTOTYPE(str2ull, unsigned long long);


a2i_inline int
str2shh(signed char *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2sh(short *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2si(int *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2sl(long *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2sll(long long *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2uhh(unsigned char *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2uh(unsigned short *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2ui(unsigned int *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2ul(unsigned long *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}


a2i_inline int
str2ull(unsigned long long *restrict n, const char *restrict s)
{
	return a2i_str2I(n, s);
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
