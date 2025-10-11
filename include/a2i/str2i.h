// SPDX-FileCopyrightText: 2023-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_H_
#define INCLUDE_A2I_STR2I_H_


#include <a2i/a2i/a2i.h>  // IWYU pragma: keep


#define str2i(TYPE, n, s)  a2i(TYPE, n, s, NULL, 0, _Minof(TYPE), _Maxof(TYPE))

#define str2shh(...)    str2i(signed char, __VA_ARGS__)
#define str2sh(...)     str2i(short, __VA_ARGS__)
#define str2si(...)     str2i(int, __VA_ARGS__)
#define str2sl(...)     str2i(long, __VA_ARGS__)
#define str2sll(...)    str2i(long long, __VA_ARGS__)

#define str2uhh(...)    str2i(unsigned char, __VA_ARGS__)
#define str2uh(...)     str2i(unsigned short, __VA_ARGS__)
#define str2ui(...)     str2i(unsigned int, __VA_ARGS__)
#define str2ul(...)     str2i(unsigned long, __VA_ARGS__)
#define str2ull(...)    str2i(unsigned long long, __VA_ARGS__)


#endif  // include guard
