// SPDX-FileCopyrightText: 2022-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_TYPETRAITS_H_
#define INCLUDE_A2I_TYPETRAITS_H_


#include <limits.h>


#define a2i_is_unsigned(x)  (((typeof(x)) -1) > 1)
#define a2i_is_signed(x)    (((typeof(x)) -1) < 1)

#define a2i_widthof(x)      (sizeof(x) * CHAR_BIT)

#define a2i_stype_max(T)                                                      \
(                                                                             \
	(T) (((((T) 1 << (a2i_widthof(T) - 2)) - 1) << 1) + 1)                \
)
#define a2i_utype_max(T)    ((T) -1)
#define a2i_type_max(T)                                                       \
(                                                                             \
	(T) (a2i_is_signed(T) ? a2i_stype_max(T) : a2i_utype_max(T))          \
)
#define a2i_type_min(T)     ((T) ~a2i_type_max(T))
#define a2i_typeof_max(x)   a2i_type_max(typeof(x))
#define a2i_typeof_min(x)   a2i_type_min(typeof(x))


#endif  // include guard
