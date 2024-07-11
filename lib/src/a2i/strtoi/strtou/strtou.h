// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef LIB_SRC_A2I_STRTOI_STRTOU_STRTOU_H_
#define LIB_SRC_A2I_STRTOI_STRTOU_STRTOU_H_


#include "lib/src/a2i/strtoi/strtou/strtou_c.h"   // IWYU pragma: keep
#include "lib/src/a2i/strtoi/strtou/strtou_nc.h"  // IWYU pragma: keep


#define a2i_strtou(s, ...)                                                    \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2i_strtou_c,                                  \
		const void *:  a2i_strtou_c,                                  \
		char *:        a2i_strtou_nc,                                 \
		void *:        a2i_strtou_nc                                  \
	)(s, __VA_ARGS__)                                                     \
)


#endif  // include guard
