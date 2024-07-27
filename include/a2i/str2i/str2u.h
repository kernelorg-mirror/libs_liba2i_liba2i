// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_STR2U_H_
#define INCLUDE_A2I_STR2I_STR2U_H_


#include <a2i/attr.h>
#include <a2i/inline.h>


#define str2u(TYPE, ...)                                                      \
(                                                                             \
	_Generic((TYPE) 0,                                                    \
		unsigned char:       str2uhh,                                 \
		unsigned short:      str2uh,                                  \
		unsigned int:        str2ui,                                  \
		unsigned long:       str2ul,                                  \
		unsigned long long:  str2ull                                  \
	)(__VA_ARGS__)                                                        \
)


#define A2I_STR2U_ATTR                                                        \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_NONNULL(1, 2)                                                \
	A2I_ATTR_STRING(2)                                                    \
	A2I_ATTR_LEAF                                                         \
	A2I_ATTR_NOTHROW


A2I_STR2U_ATTR
a2i_inline int str2uhh(unsigned char *restrict n, const char *restrict s);

A2I_STR2U_ATTR
a2i_inline int str2uh(unsigned short *restrict n, const char *restrict s);

A2I_STR2U_ATTR
a2i_inline int str2ui(unsigned int *restrict n, const char *restrict s);

A2I_STR2U_ATTR
a2i_inline int str2ul(unsigned long *restrict n, const char *restrict s);

A2I_STR2U_ATTR
a2i_inline int str2ull(unsigned long long *restrict n, const char *restrict s);


#endif  // include guard
