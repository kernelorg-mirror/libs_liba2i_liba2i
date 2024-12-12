// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_INLINE_H_
#define INCLUDE_A2I_INLINE_H_


#if defined(A2I_INTERNAL)
# define a2i_inline  inline
#else
# define a2i_inline
#endif


#endif  // include guard
