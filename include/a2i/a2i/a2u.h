// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2U_H_
#define INCLUDE_A2I_A2I_A2U_H_


#include <a2i/attr.h>
#include <a2i/qual.h>


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


#define A2I_A2U_ATTR                                                          \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_STRING(2)                                                    \


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
A2I_A2U_ATTR
int a2uhh_c(unsigned char *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
A2I_A2U_ATTR
int a2uh_c(unsigned short *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
A2I_A2U_ATTR
int a2ui_c(unsigned int *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
A2I_A2U_ATTR
int a2ul_c(unsigned long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
A2I_A2U_ATTR
int a2ull_c(unsigned long long *restrict n, const char *s,
    const char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);

A2I_A2U_ATTR
int (a2uhh)(unsigned char *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned char min, unsigned char max);
A2I_A2U_ATTR
int (a2uh)(unsigned short *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned short min, unsigned short max);
A2I_A2U_ATTR
int (a2ui)(unsigned int *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned int min, unsigned int max);
A2I_A2U_ATTR
int (a2ul)(unsigned long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long min, unsigned long max);
A2I_A2U_ATTR
int (a2ull)(unsigned long long *restrict n, char *s,
    char **a2i_nullable restrict endp, int base,
    unsigned long long min, unsigned long long max);
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif


#endif  // include guard
