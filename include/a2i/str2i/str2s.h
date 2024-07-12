// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_STR2S_H_
#define INCLUDE_A2I_STR2I_STR2S_H_


#include <a2i/attr.h>
#include <a2i/inline.h>


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


#define A2I_STR2S_ATTR                                                        \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_STRING(2)                                                    \
	A2I_ATTR_LEAF                                                         \
	A2I_ATTR_NOTHROW


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_STR2S_ATTR
a2i_inline int str2shh(signed char *restrict n, const char *s);

A2I_STR2S_ATTR
a2i_inline int str2sh(short *restrict n, const char *s);

A2I_STR2S_ATTR
a2i_inline int str2si(int *restrict n, const char *s);

A2I_STR2S_ATTR
a2i_inline int str2sl(long *restrict n, const char *s);

A2I_STR2S_ATTR
a2i_inline int str2sll(long long *restrict n, const char *s);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
