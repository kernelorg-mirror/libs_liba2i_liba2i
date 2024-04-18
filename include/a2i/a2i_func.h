// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_FUNC_H_
#define INCLUDE_A2I_A2I_FUNC_H_


#include <errno.h>

#include <a2i/attr.h>
#include <a2i/inline.h>
#include <a2i/qual.h>
#include <a2i/strtoi.h>


#define a2i_a2I_nc(n, s, endp, base, min, max)                                \
({                                                                            \
	int  status_;                                                         \
                                                                              \
	*n = _Generic(*n,                                                     \
		signed char:         a2i_strtoi,                              \
		short:               a2i_strtoi,                              \
		int:                 a2i_strtoi,                              \
		long:                a2i_strtoi,                              \
		long long:           a2i_strtoi,                              \
		unsigned char:       a2i_strtou_noneg,                        \
		unsigned short:      a2i_strtou_noneg,                        \
		unsigned int:        a2i_strtou_noneg,                        \
		unsigned long:       a2i_strtou_noneg,                        \
		unsigned long long:  a2i_strtou_noneg                         \
	)(s, endp, base, min, max, &status_);                                 \
	if (status_ != 0)                                                     \
		errno = status_;                                              \
                                                                              \
	-!!status_;                                                           \
})


#define A2I_A2I_PROTOTYPE(name, TYPE, TYPE2)                                  \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_STRING(2)                                                    \
	a2i_inline int name(TYPE *restrict n, const char *s,                  \
	    TYPE2 a2i_nullable restrict endp, int base, TYPE min, TYPE max)

#define A2I_A2I_PROTOTYPES(name, TYPE)                                       \
	A2I_A2I_PROTOTYPE(name ## _c, TYPE, const char **);                  \
	A2I_A2I_PROTOTYPE(name ## _nc, TYPE, char **)


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_A2I_PROTOTYPES(a2shh, signed char);
A2I_A2I_PROTOTYPES(a2sh, short);
A2I_A2I_PROTOTYPES(a2si, int);
A2I_A2I_PROTOTYPES(a2sl, long);
A2I_A2I_PROTOTYPES(a2sll, long long);

A2I_A2I_PROTOTYPES(a2uhh, unsigned char);
A2I_A2I_PROTOTYPES(a2uh, unsigned short);
A2I_A2I_PROTOTYPES(a2ui, unsigned int);
A2I_A2I_PROTOTYPES(a2ul, unsigned long);
A2I_A2I_PROTOTYPES(a2ull, unsigned long long);


#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wimplicit-int-conversion"
# pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
a2i_inline int
a2shh_c(signed char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    signed char min, signed char max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2sh_c(short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    short min, short max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2si_c(int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    int min, int max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2sl_c(long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long min, long max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2sll_c(long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long long min, long long max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2uhh_c(unsigned char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2uh_c(unsigned short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2ui_c(unsigned int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2ul_c(unsigned long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}


a2i_inline int
a2ull_c(unsigned long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max)
{
	return a2i_a2I_nc(n, s, (char **a2i_nullable) endp, base, min, max);
}
#pragma GCC diagnostic pop  // -Wcast-qual


a2i_inline int
a2shh_nc(signed char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2sh_nc(short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2si_nc(int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2sl_nc(long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2sll_nc(long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2uhh_nc(unsigned char *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2uh_nc(unsigned short *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2ui_nc(unsigned int *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2ul_nc(unsigned long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}


a2i_inline int
a2ull_nc(unsigned long long *restrict n, const char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max)
{
	return a2i_a2I_nc(n, s, endp, base, min, max);
}
#if defined(__clang__)
# pragma clang diagnostic pop  // -Wimplicit-int-conversion, -Wshorten-64-to-32
# pragma clang assume_nonnull end
#endif


#endif  // include guard
