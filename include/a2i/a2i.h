// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_H_
#define INCLUDE_A2I_A2I_H_


#include <assert.h>  // IWYU pragma: keep
#include <errno.h>
#include <stdint.h>

#include <a2i/attr.h>
#include <a2i/cast.h>
#include <a2i/inline.h>
#include <a2i/qual.h>
#include <a2i/strtoi.h>
#include <a2i/typetraits.h>


#define a2i(TYPE, ...)                                                        \
(                                                                             \
	_Generic((TYPE) 0,                                                    \
		signed char:         a2shh,                                   \
		short:               a2sh,                                    \
		int:                 a2si,                                    \
		long:                a2sl,                                    \
		long long:           a2sll,                                   \
                                                                              \
		unsigned char:       a2uhh,                                   \
		unsigned short:      a2uh,                                    \
		unsigned int:        a2ui,                                    \
		unsigned long:       a2ul,                                    \
		unsigned long long:  a2ull                                    \
	)(__VA_ARGS__)                                                        \
)


#define a2s(TYPE, ...)                                                        \
({                                                                            \
	static_assert(a2i_is_signed(TYPE), "");                               \
	a2i(TYPE, __VA_ARGS__);                                               \
})


#define a2u(TYPE, ...)                                                        \
({                                                                            \
	static_assert(a2i_is_unsigned(TYPE), "");                             \
	a2i(TYPE, __VA_ARGS__);                                               \
})


#define a2i_a2S(n, s, endp, base, min, max)                                   \
({                                                                            \
	int       status_;                                                    \
	intmax_t  n_;                                                         \
                                                                              \
	n_ = a2i_strtoi(s, endp, base, min, max, &status_);                   \
	*n = a2i_narrow_int_cast(typeof(*n), n_);                             \
                                                                              \
	if (status_ != 0)                                                     \
		errno = status_;                                              \
                                                                              \
	-!!status_;                                                           \
})


#define a2i_a2U(n, s, endp, base, min, max)                                   \
({                                                                            \
	int        status_;                                                   \
	uintmax_t  n_;                                                        \
                                                                              \
	n_ = a2i_strtou_noneg(s, endp, base, min, max, &status_);             \
	*n = a2i_narrow_int_cast(typeof(*n), n_);                             \
                                                                              \
	if (status_ != 0)                                                     \
		errno = status_;                                              \
                                                                              \
	-!!status_;                                                           \
})


#define A2I_A2I_PROTOTYPE(name, TYPE)                                         \
	__attribute__((__access__(write_only, 1)))                            \
	__attribute__((__access__(read_only, 2)))                             \
	__attribute__((__access__(write_only, 3)))                            \
	A2I_ATTR_STRING(2)                                                    \
	a2i_inline int name(TYPE *restrict n, const char *s,                  \
	    char **a2i_nullable restrict endp, int base, TYPE min, TYPE max)


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_A2I_PROTOTYPE(a2shh, signed char);
A2I_A2I_PROTOTYPE(a2sh, short);
A2I_A2I_PROTOTYPE(a2si, int);
A2I_A2I_PROTOTYPE(a2sl, long);
A2I_A2I_PROTOTYPE(a2sll, long long);

A2I_A2I_PROTOTYPE(a2uhh, unsigned char);
A2I_A2I_PROTOTYPE(a2uh, unsigned short);
A2I_A2I_PROTOTYPE(a2ui, unsigned int);
A2I_A2I_PROTOTYPE(a2ul, unsigned long);
A2I_A2I_PROTOTYPE(a2ull, unsigned long long);


a2i_inline int
a2shh(signed char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max)
{
	return a2i_a2S(n, s, endp, base, min, max);
}


a2i_inline int
a2sh(short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max)
{
	return a2i_a2S(n, s, endp, base, min, max);
}


a2i_inline int
a2si(int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max)
{
	return a2i_a2S(n, s, endp, base, min, max);
}


a2i_inline int
a2sl(long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max)
{
	return a2i_a2S(n, s, endp, base, min, max);
}


a2i_inline int
a2sll(long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max)
{
	return a2i_a2S(n, s, endp, base, min, max);
}


a2i_inline int
a2uhh(unsigned char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max)
{
	return a2i_a2U(n, s, endp, base, min, max);
}


a2i_inline int
a2uh(unsigned short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max)
{
	return a2i_a2U(n, s, endp, base, min, max);
}


a2i_inline int
a2ui(unsigned int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max)
{
	return a2i_a2U(n, s, endp, base, min, max);
}


a2i_inline int
a2ul(unsigned long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max)
{
	return a2i_a2U(n, s, endp, base, min, max);
}


a2i_inline int
a2ull(unsigned long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max)
{
	return a2i_a2U(n, s, endp, base, min, max);
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
