// Copyright, the authors of liba2i
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_H_
#define INCLUDE_A2I_H_


#include <errno.h>
#include <limits.h>
#include <stdint.h>


// QChar_of - possibly-qualified char of-a-string
#define a2i_QChar_of(s)  typeof                                       \
(                                                                     \
	_Generic(s,                                                   \
		const char *:  (const char){0},                       \
		const void *:  (const char){0},                       \
		char *:        (char){0},                             \
		void *:        (char){0}                              \
	)                                                             \
)


#define A2I_DEFARG__(x, ...)    (x)
#define A2I_DEFARG_(def, ...)   A2I_DEFARG__(__VA_ARGS__ __VA_OPT__(,) def)
#define A2I_DEFARG(def, arg)    A2I_DEFARG_(def, arg)


#if (__GNUC__ >= 16)
# define a2i_maxof(T)        _Maxof(T)
# define a2i_minof(T)        _Minof(T)
#else
# define a2i_widthof(x)      (sizeof(x) * CHAR_BIT)
# define a2i_is_unsigned(x)  ((typeof(x)) -1 > 1)
# define a2i_stype_max(T)    \
	((T) (((((T) 1 << (a2i_widthof(T) - 2)) - 1) << 1) + 1))
# define a2i_utype_max(T)    ((T) -1)
# define a2i_maxof(T)        \
	((T) (a2i_is_unsigned(T) ? a2i_utype_max(T) : a2i_stype_max(T)))
# define a2i_minof(T)        ((T) ~a2i_maxof(T))
#endif


#define a2i_(T, QChar, n, s, endp, base, min, max)                    \
({                                                                    \
	T      *a2i_n_ = n;                                           \
	QChar  *a2i_s_ = s;                                           \
	QChar  **a2i_ep_ = endp;                                      \
	int    a2i_b_ = base;                                         \
	T      a2i_min_ = A2I_DEFARG(a2i_minof(T), min);              \
	T      a2i_max_ = A2I_DEFARG(a2i_maxof(T), max);              \
                                                                      \
	int  a2i_st_;                                                 \
                                                                      \
	_Pragma("clang diagnostic push");                             \
	_Pragma("clang diagnostic ignored \"-Wimplicit-int-conversion\"");\
	_Pragma("clang diagnostic ignored \"-Wshorted-64-to-32\"");   \
                                                                      \
	*a2i_n_ = _Generic((T){0},                                    \
		signed char:        atosimax,                         \
		short:              atosimax,                         \
		int:                atosimax,                         \
		long:               atosimax,                         \
		long long:          atosimax,                         \
		unsigned char:      atouimax,                         \
		unsigned short:     atouimax,                         \
		unsigned int:       atouimax,                         \
		unsigned long:      atouimax,                         \
		unsigned long long: atouimax                          \
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


A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_NONNULL(1)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
intmax_t atosimax(const char *restrict s, char **restrict endp, int base,
    intmax_t min, intmax_t max, int *restrict status);
A2I_ATTR_ACCESS(read_only, 1)
A2I_ATTR_ACCESS(write_only, 2)
A2I_ATTR_ACCESS(write_only, 6)
A2I_ATTR_NONNULL(1)
A2I_ATTR_STRING(1)
A2I_ATTR_LEAF
A2I_ATTR_NOTHROW
uintmax_t atouimax(const char *restrict s, char **restrict endp, int base,
    uintmax_t min, uintmax_t max, int *restrict status);


#endif  // include guard
