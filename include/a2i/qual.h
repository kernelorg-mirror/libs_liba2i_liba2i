// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_QUAL_H_
#define INCLUDE_A2I_QUAL_H_


#if defined(__clang__)
# define a2i_nullable  _Nullable
#else
# define a2i_nullable
#endif


#endif  // include guard
