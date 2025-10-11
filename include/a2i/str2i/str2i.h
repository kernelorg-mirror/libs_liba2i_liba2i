// SPDX-FileCopyrightText: 2023-2025, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STR2I_STR2I_H_
#define INCLUDE_A2I_STR2I_STR2I_H_


#include <a2i/a2i/a2i.h>  // IWYU pragma: keep


#define str2i(TYPE, n, s)  a2i(TYPE, n, s, NULL, 0, _Minof(TYPE), _Maxof(TYPE))


#endif  // include guard
