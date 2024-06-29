// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2S_H_
#define INCLUDE_A2I_A2I_A2S_H_


#include <a2i/attr.h>
#include <a2i/qual.h>


#define a2s(TYPE, n, s, ...)                                                  \
(                                                                             \
	_Generic((void (*)(TYPE, typeof(s))) 0,                               \
		void (*)(signed char,        const char *):  a2shh_c,         \
		void (*)(signed char,        const void *):  a2shh_c,         \
		void (*)(signed char,        char *):        a2shh,           \
		void (*)(signed char,        void *):        a2shh,           \
		void (*)(short,              const char *):  a2sh_c,          \
		void (*)(short,              const void *):  a2sh_c,          \
		void (*)(short,              char *):        a2sh,            \
		void (*)(short,              void *):        a2sh,            \
		void (*)(int,                const char *):  a2si_c,          \
		void (*)(int,                const void *):  a2si_c,          \
		void (*)(int,                char *):        a2si,            \
		void (*)(int,                void *):        a2si,            \
		void (*)(long,               const char *):  a2sl_c,          \
		void (*)(long,               const void *):  a2sl_c,          \
		void (*)(long,               char *):        a2sl,            \
		void (*)(long,               void *):        a2sl,            \
		void (*)(long long,          const char *):  a2sll_c,         \
		void (*)(long long,          const void *):  a2sll_c,         \
		void (*)(long long,          char *):        a2sll,           \
		void (*)(long long,          void *):        a2sll            \
	)(n, s, __VA_ARGS__)                                                  \
)


#define a2shh(n, s, ...)                                                      \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2shh_c,                                       \
		const void *:  a2shh_c,                                       \
		char *:        a2shh,                                         \
		void *:        a2shh                                          \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2sh(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2sh_c,                                        \
		const void *:  a2sh_c,                                        \
		char *:        a2sh,                                          \
		void *:        a2sh                                           \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2si(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2si_c,                                        \
		const void *:  a2si_c,                                        \
		char *:        a2si,                                          \
		void *:        a2si                                           \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2sl(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2sl_c,                                        \
		const void *:  a2sl_c,                                        \
		char *:        a2sl,                                          \
		void *:        a2sl                                           \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2sll(n, s, ...)                                                      \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2sll_c,                                       \
		const void *:  a2sll_c,                                       \
		char *:        a2sll,                                         \
		void *:        a2sll                                          \
	)(n, s, __VA_ARGS__)                                                  \
)


#define A2I_A2S_ATTR                                                          \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_STRING(2)                                                    \


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_A2S_ATTR
int a2shh_c(signed char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
A2I_A2S_ATTR
int a2sh_c(short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    short min, short max);
A2I_A2S_ATTR
int a2si_c(int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    int min, int max);
A2I_A2S_ATTR
int a2sl_c(long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long min, long max);
A2I_A2S_ATTR
int a2sll_c(long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long long min, long long max);

A2I_A2S_ATTR
int (a2shh)(signed char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
A2I_A2S_ATTR
int (a2sh)(short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max);
A2I_A2S_ATTR
int (a2si)(int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max);
A2I_A2S_ATTR
int (a2sl)(long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max);
A2I_A2S_ATTR
int (a2sll)(long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
