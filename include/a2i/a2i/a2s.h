// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2S_H_
#define INCLUDE_A2I_A2I_A2S_H_


#include <a2i/a2i/a2i.h>


#define a2s(TYPE, ...)                                                \
(                                                                     \
	_Generic((TYPE) 0,                                            \
		signed char:  0,                                      \
		short:        0,                                      \
		int:          0,                                      \
		long:         0,                                      \
		long long:    0                                       \
	) +                                                           \
	a2i(TYPE, __VA_ARGS__)                                        \
)


#define a2shh(...)  a2i(signed char, __VA_ARGS__)
#define a2sh(...)   a2i(short, __VA_ARGS__)
#define a2si(...)   a2i(int, __VA_ARGS__)
#define a2sl(...)   a2i(long, __VA_ARGS__)
#define a2sll(...)  a2i(long long, __VA_ARGS__)


#endif  // include guard
