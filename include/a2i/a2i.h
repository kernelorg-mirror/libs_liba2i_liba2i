// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_H_
#define INCLUDE_A2I_A2I_H_


#include <assert.h>  // IWYU pragma: keep

#include <a2i/a2i_func.h>  // IWYU pragma: keep
#include <a2i/typetraits.h>


#define a2i(TYPE, ...)                                                        \
(                                                                             \
	_Generic((TYPE) 0,                                                    \
		signed char:         a2shh,                                   \
		short:               a2sh,                                    \
		int:                 a2si,                                    \
		long:                a2sl,                                    \
		long long:           a2sll,                                   \
                                                                              \
		unsigned char:       a2uhh,                                   \
		unsigned short:      a2uh,                                    \
		unsigned int:        a2ui,                                    \
		unsigned long:       a2ul,                                    \
		unsigned long long:  a2ull                                    \
	)(__VA_ARGS__)                                                        \
)


#define a2s(TYPE, ...)                                                        \
({                                                                            \
	static_assert(a2i_is_signed(TYPE), "");                               \
	a2i(TYPE, __VA_ARGS__);                                               \
})


#define a2u(TYPE, ...)                                                        \
({                                                                            \
	static_assert(a2i_is_unsigned(TYPE), "");                             \
	a2i(TYPE, __VA_ARGS__);                                               \
})


#endif  // include guard
