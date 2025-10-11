// SPDX-FileCopyrightText: 2023-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_STR2U_H_
#define INCLUDE_A2I_STR2I_STR2U_H_


#include <a2i/str2i/str2i.h>


#define str2uhh(...)    str2i(unsigned char, __VA_ARGS__)
#define str2uh(...)     str2i(unsigned short, __VA_ARGS__)
#define str2ui(...)     str2i(unsigned int, __VA_ARGS__)
#define str2ul(...)     str2i(unsigned long, __VA_ARGS__)
#define str2ull(...)    str2i(unsigned long long, __VA_ARGS__)


#endif  // include guard
