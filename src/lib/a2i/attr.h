// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef SRC_LIB_A2I_ATTR_H_
#define SRC_LIB_A2I_ATTR_H_


#include "include/a2i/attr.h"  // IWYU pragma: export
// IWYU pragma: no_include "a2i/attr.h"


#define A2I_ATTR_ALIAS(original)  __attribute__((alias(original)))

#define A2I_ATTR_VISIBILITY(v)    __attribute__((visibility(v)))


#endif  // include guard
