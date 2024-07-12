// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2U_H_
#define INCLUDE_A2I_A2I_A2U_H_


#include <a2i/a2i/a2u_.h>  // IWYU pragma: keep


#define a2u(TYPE, n, s, ...)                                                  \
(                                                                             \
	_Generic((void (*)(TYPE, typeof(s))) 0,                               \
		void (*)(unsigned char,      const char *):  a2uhh_c,         \
		void (*)(unsigned char,      const void *):  a2uhh_c,         \
		void (*)(unsigned char,      char *):        a2uhh_nc,        \
		void (*)(unsigned char,      void *):        a2uhh_nc,        \
		void (*)(unsigned short,     const char *):  a2uh_c,          \
		void (*)(unsigned short,     const void *):  a2uh_c,          \
		void (*)(unsigned short,     char *):        a2uh_nc,         \
		void (*)(unsigned short,     void *):        a2uh_nc,         \
		void (*)(unsigned int,       const char *):  a2ui_c,          \
		void (*)(unsigned int,       const void *):  a2ui_c,          \
		void (*)(unsigned int,       char *):        a2ui_nc,         \
		void (*)(unsigned int,       void *):        a2ui_nc,         \
		void (*)(unsigned long,      const char *):  a2ul_c,          \
		void (*)(unsigned long,      const void *):  a2ul_c,          \
		void (*)(unsigned long,      char *):        a2ul_nc,         \
		void (*)(unsigned long,      void *):        a2ul_nc,         \
		void (*)(unsigned long long, const char *):  a2ull_c,         \
		void (*)(unsigned long long, const void *):  a2ull_c,         \
		void (*)(unsigned long long, char *):        a2ull_nc,        \
		void (*)(unsigned long long, void *):        a2ull_nc         \
	)(n, s, __VA_ARGS__)                                                  \
)


#define a2uhh(n, s, ...)                                                      \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2uhh_c,                                       \
		const void *:  a2uhh_c,                                       \
		char *:        a2uhh_nc,                                      \
		void *:        a2uhh_nc                                       \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2uh(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2uh_c,                                        \
		const void *:  a2uh_c,                                        \
		char *:        a2uh_nc,                                       \
		void *:        a2uh_nc                                        \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2ui(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2ui_c,                                        \
		const void *:  a2ui_c,                                        \
		char *:        a2ui_nc,                                       \
		void *:        a2ui_nc                                        \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2ul(n, s, ...)                                                       \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2ul_c,                                        \
		const void *:  a2ul_c,                                        \
		char *:        a2ul_nc,                                       \
		void *:        a2ul_nc                                        \
	)(n, s, __VA_ARGS__)                                                  \
)

#define a2ull(n, s, ...)                                                      \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2ull_c,                                       \
		const void *:  a2ull_c,                                       \
		char *:        a2ull_nc,                                      \
		void *:        a2ull_nc                                       \
	)(n, s, __VA_ARGS__)                                                  \
)


#endif  // include guard
