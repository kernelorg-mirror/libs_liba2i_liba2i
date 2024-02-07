// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_INLINE_H_
#define INCLUDE_A2I_INLINE_H_


#include <a2i/ftm.h>


#if   (A2I_FTM_INLINE == 0)
# define a2i_inline  __attribute__((__noipa__)) inline
#elif (A2I_FTM_INLINE == 1)
# define a2i_inline  inline
#elif (A2I_FTM_INLINE == 2)
# define a2i_inline  static inline
#else
# warning "Unsupported A2I_FTM_INLINE value"
#endif


#endif  // include guard
