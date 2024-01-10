// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_CAST_H_
#define INCLUDE_A2I_CAST_H_


#include <a2i/typetraits.h>


#define a2i_narrow_int_cast(T, e)                                             \
({                                                                            \
	__auto_type  e_ = e;                                                  \
                                                                              \
	static_assert(__builtin_classify_type((T) 0) == 1);                   \
	static_assert(__builtin_classify_type((typeof(e_)) 0) == 1);          \
	static_assert(a2i_is_signed(T) == a2i_is_signed(typeof(e_)));         \
	static_assert(sizeof(T) <= sizeof(e_));                               \
                                                                              \
	(T) (e_);                                                             \
})


#endif  // include guard
