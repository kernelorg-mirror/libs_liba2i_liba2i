// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2I_H_
#define INCLUDE_A2I_A2I_A2I_H_


#include <errno.h>

#include <a2i/strtoi/strtoi.h>  // IWYU pragma: keep
#include <a2i/strtoi/strtou.h>  // IWYU pragma: keep


// QChar_of - possibly-qualified char of-a-string
#define a2i_QChar_of(s)  typeof                                       \
(                                                                     \
	_Generic(s,                                                   \
		const char *:  (const char){},                        \
		const void *:  (const char){},                        \
		char *:        (char){},                              \
		void *:        (char){}                               \
	)                                                             \
)


#define A2I_VA_IFNOT_(...)       __VA_ARGS__
#define A2I_VA_IFNOT_1(...)
#define A2I_VA_IFNOT(cond, ...)  A2I_VA_IFNOT_ ## cond (__VA_ARGS__)
#define A2I_DEFAULT_(def, ...)                                        \
(                                                                     \
	/* default:  */ A2I_VA_IFNOT(__VA_OPT__(1), def)              \
	/* override: */ __VA_OPT__(__VA_ARGS__)                       \
)
#define A2I_DEFAULT(def, ovr)  A2I_DEFAULT_(def, ovr)


#define a2i_(T, QChar, n, s, endp, base, min, max)                    \
({                                                                    \
	T      *a2i_n_ = n;                                           \
	QChar  *a2i_s_ = s;                                           \
	QChar  **a2i_ep_ = endp;                                      \
	int    a2i_b_ = base;                                         \
	T      a2i_min_ = A2I_DEFAULT(_Minof(T), min);                \
	T      a2i_max_ = A2I_DEFAULT(_Maxof(T), max);                \
                                                                      \
	int  a2i_st_;                                                 \
                                                                      \
	_Pragma("clang diagnostic push");                             \
	_Pragma("clang diagnostic ignored \"-Wimplicit-int-conversion\"");\
	_Pragma("clang diagnostic ignored \"-Wshorted-64-to-32\"");   \
                                                                      \
	*a2i_n_ = _Generic((T) 0,                                     \
		signed char:        a2i_strtoi2,                      \
		short:              a2i_strtoi2,                      \
		int:                a2i_strtoi2,                      \
		long:               a2i_strtoi2,                      \
		long long:          a2i_strtoi2,                      \
		unsigned char:      a2i_strtou2,                      \
		unsigned short:     a2i_strtou2,                      \
		unsigned int:       a2i_strtou2,                      \
		unsigned long:      a2i_strtou2,                      \
		unsigned long long: a2i_strtou2                       \
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


#define a2shh(...)  a2i(signed char, __VA_ARGS__)
#define a2sh(...)   a2i(short, __VA_ARGS__)
#define a2si(...)   a2i(int, __VA_ARGS__)
#define a2sl(...)   a2i(long, __VA_ARGS__)
#define a2sll(...)  a2i(long long, __VA_ARGS__)

#define a2uhh(...)  a2i(unsigned char, __VA_ARGS__)
#define a2uh(...)   a2i(unsigned short, __VA_ARGS__)
#define a2ui(...)   a2i(unsigned int, __VA_ARGS__)
#define a2ul(...)   a2i(unsigned long, __VA_ARGS__)
#define a2ull(...)  a2i(unsigned long long, __VA_ARGS__)


#define str2i(T, n, s)  a2i(T, n, s, NULL, 0,,)

#define str2shh(...)    str2i(signed char, __VA_ARGS__)
#define str2sh(...)     str2i(short, __VA_ARGS__)
#define str2si(...)     str2i(int, __VA_ARGS__)
#define str2sl(...)     str2i(long, __VA_ARGS__)
#define str2sll(...)    str2i(long long, __VA_ARGS__)

#define str2uhh(...)    str2i(unsigned char, __VA_ARGS__)
#define str2uh(...)     str2i(unsigned short, __VA_ARGS__)
#define str2ui(...)     str2i(unsigned int, __VA_ARGS__)
#define str2ul(...)     str2i(unsigned long, __VA_ARGS__)
#define str2ull(...)    str2i(unsigned long long, __VA_ARGS__)


#endif  // include guard
