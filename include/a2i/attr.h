// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_ATTR_H_
#define INCLUDE_A2I_ATTR_H_


#if !defined(__has_attribute)
# define __has_attribute(x)  0
#endif


#if __has_attribute(__null_terminated_string_arg__)
# define A2I_ATTR_STRING(n)  __attribute__((__null_terminated_string_arg__(n)))
#else
# define A2I_ATTR_STRING(n)
#endif

#if __has_attribute(__access__)
# define A2I_ATTR_ACCESS(...)      __attribute__((__access__(__VA_ARGS__)))
#else
# define A2I_ATTR_ACCESS(...)
#endif

#if __has_attribute(__leaf__)
# define A2I_ATTR_LEAF             __attribute__((__leaf__))
#else
# define A2I_ATTR_LEAF
#endif

#if __has_attribute(__nonnull__)
# define A2I_ATTR_NONNULL(...)     __attribute__((__nonnull__(__VA_ARGS__)))
#else
# define A2I_ATTR_NONNULL(...)
#endif

#if __has_attribute(__nothrow__)
# define A2I_ATTR_NOTHROW          __attribute__((__nothrow__))
#else
# define A2I_ATTR_NOTHROW
#endif

#if __has_attribute(__alias__)
# define A2I_ATTR_ALIAS(original)  __attribute__((__alias__(original)))
#else
# define A2I_ATTR_ALIAS(original)
#endif

#if __has_attribute(__visibility__)
# define A2I_ATTR_VISIBILITY(v)    __attribute__((__visibility__(v)))
#else
# define A2I_ATTR_VISIBILITY(v)
#endif


#endif  // include guard
