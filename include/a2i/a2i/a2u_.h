// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#ifndef INCLUDE_A2I_A2I_A2U__H_
#define INCLUDE_A2I_A2I_A2U__H_


#include <errno.h>

#include <a2i/attr.h>
#include <a2i/inline.h>
#include <a2i/strtoi/strtou_noneg/strtou_noneg.h>


#define A2I_A2U_ATTR                                                          \
	A2I_ATTR_ACCESS(write_only, 1)                                        \
	A2I_ATTR_ACCESS(read_only, 2)                                         \
	A2I_ATTR_ACCESS(write_only, 3)                                        \
	A2I_ATTR_NONNULL(1, 2)                                                \
	A2I_ATTR_STRING(2)                                                    \
	A2I_ATTR_LEAF                                                         \
	A2I_ATTR_NOTHROW


A2I_A2U_ATTR
a2i_inline
int a2uhh_nc(unsigned char *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned char min, unsigned char max);

A2I_A2U_ATTR
a2i_inline
int a2uh_nc(unsigned short *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned short min, unsigned short max);

A2I_A2U_ATTR
a2i_inline
int a2ui_nc(unsigned int *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned int min, unsigned int max);

A2I_A2U_ATTR
a2i_inline
int a2ul_nc(unsigned long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long min, unsigned long max);

A2I_A2U_ATTR
a2i_inline
int a2ull_nc(unsigned long long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long long min, unsigned long long max);


A2I_A2U_ATTR
int a2uhh_c(unsigned char *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned char min, unsigned char max);

A2I_A2U_ATTR
int a2uh_c(unsigned short *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned short min, unsigned short max);

A2I_A2U_ATTR
int a2ui_c(unsigned int *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned int min, unsigned int max);

A2I_A2U_ATTR
int a2ul_c(unsigned long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned long min, unsigned long max);

A2I_A2U_ATTR
int a2ull_c(unsigned long long *restrict n, const char *restrict s,
    const char **restrict endp, int base,
    unsigned long long min, unsigned long long max);


#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wimplicit-int-conversion"
# pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif
inline int
a2uhh_nc(unsigned char *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned char min, unsigned char max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2uh_nc(unsigned short *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned short min, unsigned short max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2ui_nc(unsigned int *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned int min, unsigned int max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2ul_nc(unsigned long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long min, unsigned long max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}

inline int
a2ull_nc(unsigned long long *restrict n, char *restrict s,
    char **restrict endp, int base,
    unsigned long long min, unsigned long long max)
{
	int  status;

	*n = a2i_strtou_noneg(s, endp, base, min, max, &status);
	if (status != 0)
		errno = status;

	return -!!status;
}
#if defined(__clang__)
# pragma clang diagnostic pop  // -Wimplicit-int-conversion, -Wshorten-64-to-32
#endif


#endif  // include guard
