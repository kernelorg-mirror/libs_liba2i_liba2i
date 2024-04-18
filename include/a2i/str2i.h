// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_H_
#define INCLUDE_A2I_STR2I_H_


#include <a2i/attr.h>


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
(                                                                             \
	_Generic((TYPE) 0,                                                    \
		unsigned char:       str2uhh,                                 \
		unsigned short:      str2uh,                                  \
		unsigned int:        str2ui,                                  \
		unsigned long:       str2ul,                                  \
		unsigned long long:  str2ull                                  \
	)(__VA_ARGS__)                                                        \
)


#define A2I_STR2I_ATTR                                                        \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_STRING(2)                                                    \


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_STR2I_ATTR int str2shh(signed char *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2sh(short *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2si(int *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2sl(long *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2sll(long long *restrict n, const char *restrict s);

A2I_STR2I_ATTR int str2uhh(unsigned char *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2uh(unsigned short *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2ui(unsigned int *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2ul(unsigned long *restrict n, const char *restrict s);
A2I_STR2I_ATTR int str2ull(unsigned long long *restrict n, const char *restrict s);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
