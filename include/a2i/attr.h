// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_ATTR_H_
#define INCLUDE_A2I_ATTR_H_


#if (__GNUC__ >= 14)
# define A2I_ATTR_STRING(n)  __attribute__((__null_terminated_string_arg__(n)))
#else
# define A2I_ATTR_STRING(n)
#endif


#endif  // include guard
