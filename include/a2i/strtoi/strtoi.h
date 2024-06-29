// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STRTOI_STRTOI_H_
#define INCLUDE_A2I_STRTOI_STRTOI_H_


#include <stdint.h>

#include <a2i/attr.h>
#include <a2i/qual.h>


#define a2i_strtoi(s, ...)                                                    \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2i_strtoi_c,                                  \
		const void *:  a2i_strtoi_c,                                  \
		char *:        a2i_strtoi,                                    \
		void *:        a2i_strtoi                                     \
	)(s, __VA_ARGS__)                                                     \
)


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_STRING(1)
intmax_t a2i_strtoi_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status);

A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_STRING(1)
intmax_t (a2i_strtoi)(char *s,
    char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
