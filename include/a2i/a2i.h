// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_H_
#define INCLUDE_A2I_A2I_H_


#include <a2i/attr.h>
#include <a2i/qual.h>


#define a2i(TYPE, n, s, ...)                                                  \
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
		void (*)(long long,          void *):        a2sll,           \
		void (*)(unsigned char,      const char *):  a2uhh_c,         \
		void (*)(unsigned char,      const void *):  a2uhh_c,         \
		void (*)(unsigned char,      char *):        a2uhh,           \
		void (*)(unsigned char,      void *):        a2uhh,           \
		void (*)(unsigned short,     const char *):  a2uh_c,          \
		void (*)(unsigned short,     const void *):  a2uh_c,          \
		void (*)(unsigned short,     char *):        a2uh,            \
		void (*)(unsigned short,     void *):        a2uh,            \
		void (*)(unsigned int,       const char *):  a2ui_c,          \
		void (*)(unsigned int,       const void *):  a2ui_c,          \
		void (*)(unsigned int,       char *):        a2ui,            \
		void (*)(unsigned int,       void *):        a2ui,            \
		void (*)(unsigned long,      const char *):  a2ul_c,          \
		void (*)(unsigned long,      const void *):  a2ul_c,          \
		void (*)(unsigned long,      char *):        a2ul,            \
		void (*)(unsigned long,      void *):        a2ul,            \
		void (*)(unsigned long long, const char *):  a2ull_c,         \
		void (*)(unsigned long long, const void *):  a2ull_c,         \
		void (*)(unsigned long long, char *):        a2ull,           \
		void (*)(unsigned long long, void *):        a2ull            \
	)(n, s, __VA_ARGS__)                                                  \
)


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

#define a2u(TYPE, n, s, ...)                                                  \
(                                                                             \
	_Generic((void (*)(TYPE, typeof(s))) 0,                               \
		void (*)(unsigned char,      const char *):  a2uhh_c,         \
		void (*)(unsigned char,      const void *):  a2uhh_c,         \
		void (*)(unsigned char,      char *):        a2uhh,           \
		void (*)(unsigned char,      void *):        a2uhh,           \
		void (*)(unsigned short,     const char *):  a2uh_c,          \
		void (*)(unsigned short,     const void *):  a2uh_c,          \
		void (*)(unsigned short,     char *):        a2uh,            \
		void (*)(unsigned short,     void *):        a2uh,            \
		void (*)(unsigned int,       const char *):  a2ui_c,          \
		void (*)(unsigned int,       const void *):  a2ui_c,          \
		void (*)(unsigned int,       char *):        a2ui,            \
		void (*)(unsigned int,       void *):        a2ui,            \
		void (*)(unsigned long,      const char *):  a2ul_c,          \
		void (*)(unsigned long,      const void *):  a2ul_c,          \
		void (*)(unsigned long,      char *):        a2ul,            \
		void (*)(unsigned long,      void *):        a2ul,            \
		void (*)(unsigned long long, const char *):  a2ull_c,         \
		void (*)(unsigned long long, const void *):  a2ull_c,         \
		void (*)(unsigned long long, char *):        a2ull,           \
		void (*)(unsigned long long, void *):        a2ull            \
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


#define a2uhh(n, s, ...)                                                      \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2uhh_c,                                       \
		const void *:  a2uhh_c,                                       \
		char *:        a2uhh,                                         \
		void *:        a2uhh                                          \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2uh(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2uh_c,                                        \
		const void *:  a2uh_c,                                        \
		char *:        a2uh,                                          \
		void *:        a2uh                                           \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2ui(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2ui_c,                                        \
		const void *:  a2ui_c,                                        \
		char *:        a2ui,                                          \
		void *:        a2ui                                           \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2ul(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2ul_c,                                        \
		const void *:  a2ul_c,                                        \
		char *:        a2ul,                                          \
		void *:        a2ul                                           \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2ull(n, s, ...)                                                      \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2ull_c,                                       \
		const void *:  a2ull_c,                                       \
		char *:        a2ull,                                         \
		void *:        a2ull                                          \
	)(n, s, __VA_ARGS__)                                                  \
)


#define A2I_A2I_ATTR                                                          \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_STRING(2)                                                    \


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_A2I_ATTR
int a2shh_c(signed char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
A2I_A2I_ATTR
int a2sh_c(short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    short min, short max);
A2I_A2I_ATTR
int a2si_c(int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    int min, int max);
A2I_A2I_ATTR
int a2sl_c(long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long min, long max);
A2I_A2I_ATTR
int a2sll_c(long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    long long min, long long max);

A2I_A2I_ATTR
int a2uhh_c(unsigned char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
A2I_A2I_ATTR
int a2uh_c(unsigned short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
A2I_A2I_ATTR
int a2ui_c(unsigned int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
A2I_A2I_ATTR
int a2ul_c(unsigned long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
A2I_A2I_ATTR
int a2ull_c(unsigned long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);


A2I_A2I_ATTR
int (a2shh)(signed char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    signed char min, signed char max);
A2I_A2I_ATTR
int (a2sh)(short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    short min, short max);
A2I_A2I_ATTR
int (a2si)(int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    int min, int max);
A2I_A2I_ATTR
int (a2sl)(long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long min, long max);
A2I_A2I_ATTR
int (a2sll)(long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    long long min, long long max);

A2I_A2I_ATTR
int (a2uhh)(unsigned char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
A2I_A2I_ATTR
int (a2uh)(unsigned short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
A2I_A2I_ATTR
int (a2ui)(unsigned int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
A2I_A2I_ATTR
int (a2ul)(unsigned long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
A2I_A2I_ATTR
int (a2ull)(unsigned long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
