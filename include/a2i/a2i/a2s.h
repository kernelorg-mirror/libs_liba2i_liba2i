// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2S_H_
#define INCLUDE_A2I_A2I_A2S_H_


#include <a2i/a2i/a2s_.h>  // IWYU pragma: keep


#define a2s(TYPE, n, s, ...)                                                  \
(                                                                             \
	_Generic((void (*)(TYPE, typeof(s))) 0,                               \
		void (*)(signed char,        const char *):  a2shh_c,         \
		void (*)(signed char,        const void *):  a2shh_c,         \
		void (*)(signed char,        char *):        a2shh_nc,        \
		void (*)(signed char,        void *):        a2shh_nc,        \
		void (*)(short,              const char *):  a2sh_c,          \
		void (*)(short,              const void *):  a2sh_c,          \
		void (*)(short,              char *):        a2sh_nc,         \
		void (*)(short,              void *):        a2sh_nc,         \
		void (*)(int,                const char *):  a2si_c,          \
		void (*)(int,                const void *):  a2si_c,          \
		void (*)(int,                char *):        a2si_nc,         \
		void (*)(int,                void *):        a2si_nc,         \
		void (*)(long,               const char *):  a2sl_c,          \
		void (*)(long,               const void *):  a2sl_c,          \
		void (*)(long,               char *):        a2sl_nc,         \
		void (*)(long,               void *):        a2sl_nc,         \
		void (*)(long long,          const char *):  a2sll_c,         \
		void (*)(long long,          const void *):  a2sll_c,         \
		void (*)(long long,          char *):        a2sll_nc,        \
		void (*)(long long,          void *):        a2sll_nc         \
	)(n, s, __VA_ARGS__)                                                  \
)


#define a2shh(...)  a2s(signed char, __VA_ARGS__)
#define a2sh(...)   a2s(short, __VA_ARGS__)
#define a2si(...)   a2s(int, __VA_ARGS__)
#define a2sl(...)   a2s(long, __VA_ARGS__)
#define a2sll(...)  a2s(long long, __VA_ARGS__)


#endif  // include guard
