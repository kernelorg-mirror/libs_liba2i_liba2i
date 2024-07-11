// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_ATTR_H_
#define LIB_SRC_A2I_ATTR_H_


#include "include/a2i/attr.h"  // IWYU pragma: export
// IWYU pragma: no_include "a2i/attr.h"


#define A2I_ATTR_ALIAS(original)  __attribute__((alias(original)))


#endif  // include guard
