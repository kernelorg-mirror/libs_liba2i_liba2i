// SPDX-FileCopyrightText: 2023-2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/strtoi.h>

#include <errno.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/param.h>

#include <a2i/qual.h>


#define a2i_strtoI(TYPE, s, endp, base, min, max, status)                     \
({                                                                            \
	char  *s_ = s;                                                        \
	char  **endp_ = endp;                                                 \
	int   base_ = base;                                                   \
	TYPE  min_ = min;                                                     \
	TYPE  max_ = max;                                                     \
	int   *status_ = status;                                              \
                                                                              \
	int   errno_saved_, st_;                                              \
	char  *e_;                                                            \
	TYPE  n_;                                                             \
                                                                              \
	if (endp_ == NULL)                                                    \
		endp_ = &e_;                                                  \
	if (status_ == NULL)                                                  \
		status_ = &st_;                                               \
                                                                              \
	if (base != 0 && (base_ < 2 || base_ > 36)) {                         \
		*status_ = EINVAL;                                            \
		n_ = 0;                                                       \
                                                                              \
	} else {                                                              \
		errno_saved_ = errno;                                         \
		errno = 0;                                                    \
		n_ = _Generic((TYPE) 0,                                       \
			intmax_t:  strtoimax,                                 \
			uintmax_t: strtoumax                                  \
		)(s_, endp_, base_);                                          \
                                                                              \
		if (*endp_ == s_)                                             \
			*status_ = ECANCELED;                                 \
		else if (errno == ERANGE || n_ < min_ || n_ > max_)           \
			*status_ = ERANGE;                                    \
		else if (**endp_ != '\0')                                     \
			*status_ = ENOTSUP;                                   \
		else                                                          \
			*status_ = 0;                                         \
                                                                              \
		errno = errno_saved_;                                         \
	}                                                                     \
	MAX(min_, MIN(max_, n_));                                             \
})


#if defined(__clang__)
# pragma clang assume_nonnull begin
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
intmax_t
a2i_strtoi_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtoi((char *) s, (char **a2i_nullable) endp, base,
	                  min, max, status);
}

uintmax_t
a2i_strtou_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtou((char *) s, (char **a2i_nullable) endp, base,
	                  min, max, status);
}

uintmax_t
a2i_strtou_noneg_c(const char *s,
    const char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtou_noneg((char *) s, (char **a2i_nullable) endp, base,
	                        min, max, status);
}
#pragma GCC diagnostic pop


intmax_t
(a2i_strtoi)(char *s,
    char **a2i_nullable restrict endp, int base,
    intmax_t min, intmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtoI(intmax_t, s, endp, base, min, max, status);
}

uintmax_t
(a2i_strtou)(char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	return a2i_strtoI(uintmax_t, s, endp, base, min, max, status);
}

uintmax_t
(a2i_strtou_noneg)(char *s,
    char **a2i_nullable restrict endp, int base,
    uintmax_t min, uintmax_t max, int *a2i_nullable restrict status)
{
	int  st;

	if (status == NULL)
		status = &st;
	if (a2i_strtoi(s, endp, base, 0, 1, status) == 0 && *status == ERANGE)
		return min;

	return a2i_strtou(s, endp, base, min, max, status);
}
#if defined(__clang__)
# pragma clang assume_nonnull end
#endif
