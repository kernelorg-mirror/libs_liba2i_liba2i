// SPDX-FileCopyrightText: 2023-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_STR2S_H_
#define INCLUDE_A2I_STR2I_STR2S_H_


#include <a2i/str2i/str2i.h>


#define str2shh(...)    str2i(signed char, __VA_ARGS__)
#define str2sh(...)     str2i(short, __VA_ARGS__)
#define str2si(...)     str2i(int, __VA_ARGS__)
#define str2sl(...)     str2i(long, __VA_ARGS__)
#define str2sll(...)    str2i(long long, __VA_ARGS__)


#endif  // include guard
