// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2I_H_
#define INCLUDE_A2I_A2I_A2I_H_


#include <errno.h>

#include <a2i/strtoi/strtoi.h>  // IWYU pragma: keep
#include <a2i/strtoi/strtou_noneg.h>  // IWYU pragma: keep


// QChar_of - possibly-qualified char of-a-string
#define a2i_QChar_of(s)  typeof                                       \
(                                                                     \
	_Generic(s,                                                   \
		const char *:  *(const char *) "",                    \
		const void *:  *(const char *) "",                    \
		char *:        *(char *) "",                          \
		void *:        *(char *) ""                           \
	)                                                             \
)


#define a2i_(T, QChar, n, s, endp, base, min, max)                    \
({                                                                    \
	T      *a2i_n_ = n;                                           \
	QChar  *a2i_s_ = s;                                           \
	QChar  **a2i_ep_ = endp;                                      \
	int    a2i_b_ = base;                                         \
	T      a2i_min_ = min;                                        \
	T      a2i_max_ = max;                                        \
                                                                      \
	int  a2i_st_;                                                 \
                                                                      \
	_Pragma("clang diagnostic push");                             \
	_Pragma("clang diagnostic ignored \"-Wimplicit-int-conversion\"");\
	_Pragma("clang diagnostic ignored \"-Wshorted-64-to-32\"");   \
                                                                      \
	*a2i_n_ = _Generic((T) 0,                                     \
		signed char:        a2i_strtoi,                       \
		short:              a2i_strtoi,                       \
		int:                a2i_strtoi,                       \
		long:               a2i_strtoi,                       \
		long long:          a2i_strtoi,                       \
		unsigned char:      a2i_strtou_noneg,                 \
		unsigned short:     a2i_strtou_noneg,                 \
		unsigned int:       a2i_strtou_noneg,                 \
		unsigned long:      a2i_strtou_noneg,                 \
		unsigned long long: a2i_strtou_noneg                  \
	)(a2i_s_, (char **) a2i_ep_, a2i_b_, a2i_min_, a2i_max_, &a2i_st_);\
                                                                      \
	_Pragma("clang diagnostic pop");                              \
                                                                      \
	if (a2i_st_ != 0)                                             \
		errno = a2i_st_;                                      \
	-!!a2i_st_;                                                   \
})


// a2i - alpha to integer
#define a2i(T, n, s, ...)  a2i_(T, a2i_QChar_of(s), n, s, __VA_ARGS__)


#endif  // include guard
