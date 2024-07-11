// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_STRTOI_STRTOU_NONEG_STRTOU_NONEG_H_
#define INCLUDE_A2I_STRTOI_STRTOU_NONEG_STRTOU_NONEG_H_


#include <a2i/strtoi/strtou_noneg/strtou_noneg_c.h>
#include <a2i/strtoi/strtou_noneg/strtou_noneg_nc.h>


#define a2i_strtou_noneg(s, ...)                                              \
(                                                                             \
	_Generic(s,                                                           \
		const char *:  a2i_strtou_noneg_c,                            \
		const void *:  a2i_strtou_noneg_c,                            \
		char *:        a2i_strtou_noneg_nc,                           \
		void *:        a2i_strtou_noneg_nc                            \
	)(s, __VA_ARGS__)                                                     \
)


#endif  // include guard
