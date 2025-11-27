// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i.h>

#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>


static void test_null(void);
static void test_base(void);
static void test_leading_text(void);
static void test_leading_space(void);
static void test_range(void);
static void test_trailing_text(void);


int
main(void)
{
	test_null();
	test_base();
	test_leading_text();
	test_leading_space();
	test_range();
	test_trailing_text();
}


static void
test_null(void)
{
	long        n;
	const char  *e;

	assert(a2sl(&n, "x99z", NULL, 1, -7, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(a2sl(&n, "x99z", &e, 1, -7, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "x99z") == 0);

	assert(a2sl(&n, "x99z", NULL, 0, -7, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(a2sl(&n, "x99z", &e, 0, -7, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "x99z") == 0);

	assert(a2sl(&n, "99z", NULL, 0, -7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(a2sl(&n, "99z", &e, 0, -7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "z") == 0);

	assert(a2sl(&n, "9z", NULL, 0, -7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(a2sl(&n, "9z", &e, 0, -7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, "z") == 0);

	errno = 0;

	assert(a2sl(&n, "9", NULL, 0, -7, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(a2sl(&n, "9", &e, 0, -7, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
}


static void
test_base(void)
{
	long        n;
	const char  *e;

	assert(a2sl(&n, "1", &e, 1, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);
	assert(a2sl(&n, "1", &e, -1, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);
	assert(a2sl(&n, "1", &e, -2, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);
	assert(a2sl(&n, "1", &e, 37, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);
	assert(a2sl(&n, "1", &e, 38, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);
	assert(a2sl(&n, "1", &e, 1, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);

	assert(a2sl(&n, "", &e, 1, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "foo", &e, 1, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "foo") == 0);
	assert(a2sl(&n, "43", &e, 1, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "43") == 0);
	assert(a2sl(&n, "1", &e, 1, -42, -7) == -1);
	assert(n == -7);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);
	assert(a2sl(&n, "1", &e, 1, 42, -42) == -1);
	assert(n == 42);
	assert(errno == EINVAL);
	assert(strcmp(e, "1") == 0);
	assert(a2sl(&n, "4foo", &e, 1, -42, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "4foo") == 0);

	errno = 0;

	assert(a2sl(&n, "1", &e, 0, -42, 42) == 0);
	assert(n == 1);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "1", &e, 2, -42, 42) == 0);
	assert(n == 1);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "1", &e, 3, -42, 42) == 0);
	assert(n == 1);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "1", &e, 35, -42, 42) == 0);
	assert(n == 1);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "1", &e, 36, -42, 42) == 0);
	assert(n == 1);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2sl(&n, "0b11", &e, 0, -42, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0B11", &e, 0, -42, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0b11", &e, 0, -42, 42) == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0B11", &e, 0, -42, 42) == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "011", &e, 0, -42, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-011", &e, 0, -42, 42) == 0);
	assert(n == -9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "11", &e, 0, -42, 42) == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-11", &e, 0, -42, 42) == 0);
	assert(n == -11);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0x11", &e, 0, -42, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0X11", &e, 0, -42, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0x11", &e, 0, -42, 42) == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0X11", &e, 0, -42, 42) == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2sl(&n, "011", &e, 2, -42, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "11", &e, 2, -42, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0b11", NULL, 2, -42, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0B11", NULL, 2, -42, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-011", &e, 2, -42, 42) == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-11", &e, 2, -42, 42) == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0b11", NULL, 2, -42, 42) == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0B11", NULL, 2, -42, 42) == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "011", &e, 16, -42, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "11", &e, 16, -42, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0x11", &e, 16, -42, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0X11", &e, 16, -42, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-011", &e, 16, -42, 42) == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-11", &e, 16, -42, 42) == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0x11", &e, 16, -42, 42) == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0X11", &e, 16, -42, 42) == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2sl(&n, "011", &e, 7, -42, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "11", &e, 7, -42, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-011", &e, 7, -42, 42) == 0);
	assert(n == -8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-11", &e, 7, -42, 42) == 0);
	assert(n == -8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "011", &e, 8, -42, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "11", &e, 8, -42, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-011", &e, 8, -42, 42) == 0);
	assert(n == -9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-11", &e, 8, -42, 42) == 0);
	assert(n == -9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "z", &e, 36, -42, 42) == 0);
	assert(n == 35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "Z", &e, 36, -42, 42) == 0);
	assert(n == 35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-z", &e, 36, -42, 42) == 0);
	assert(n == -35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-Z", &e, 36, -42, 42) == 0);
	assert(n == -35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
}


static void
test_leading_text(void)
{
	long        n;
	const char  *e;

	assert(a2sl(&n, "", &e, 0, -42, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "foo", &e, 0, -42, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "foo") == 0);
	assert(a2sl(&n, "foo 7", &e, 0, -42, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "foo 7") == 0);
	assert(a2sl(&n, "", &e, 0, 42, -42) == -1);
	assert(n == 42);
	assert(errno == ECANCELED);
	assert(strcmp(e, "") == 0);
}


static void
test_leading_space(void)
{
	long        n;
	const char  *e;

	assert(a2sl(&n, " 1", &e, 0, -42, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, " 1") == 0);
	assert(a2sl(&n, "\ta", &e, 16, -42, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "\ta") == 0);
	assert(a2sl(&n, "\n-a", &e, 16, -42, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "\n-a") == 0);
}


static void
test_range(void)
{
	long        n;
	const char  *e;

	assert(a2sl(&n, "-9", &e, 0, -7, 42) == -1);
	assert(n == -7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-8", &e, 0, -7, 42) == -1);
	assert(n == -7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "43", &e, 0, -7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "44", &e, 0, -7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2sl(&n, "7", &e, 0, 7, -42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "42", &e, 0, 7, -42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2sl(&n, "-9z", &e, 0, -7, 42) == -1);
	assert(n == -7);
	assert(errno == ERANGE);
	assert(strcmp(e, "z") == 0);
	assert(a2sl(&n, "-9 ", &e, 0, -7, 42) == -1);
	assert(n == -7);
	assert(errno == ERANGE);
	assert(strcmp(e, " ") == 0);

	errno = 0;

	assert(a2sl(&n, "-7", &e, 0, -7, 42) == 0);
	assert(n == -7);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-6", &e, 0, -7, 42) == 0);
	assert(n == -6);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "41", &e, 0, -7, 42) == 0);
	assert(n == 41);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "42", &e, 0, -7, 42) == 0);
	assert(n == 42);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2sl(&n, "-1", &e, 0,,) == 0);
	assert(n == -1);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0x7FFFffffFFFFffff", &e, 0,,) == 0);
	assert(n == 0x7FFFffffFFFFffff);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0x8000000000000000", &e, 0,,) == 0);
	assert(n == LONG_MIN);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "0xFFFFffffFFFFffff", &e, 0,,) == -1);
	assert(n == LONG_MAX);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2sl(&n, "-0xFFFFffffFFFFffff", &e, 0,,) == -1);
	assert(n == LONG_MIN);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
}


static void
test_trailing_text(void)
{
	long        n;
	const char  *e;

	assert(a2sl(&n, "9 fff 7", &e, 0, -7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, " fff 7") == 0);
	assert(a2sl(&n, "9\t", &e, 0, -7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, "\t") == 0);
	assert(a2sl(&n, "9 ", &e, 0, -7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, " ") == 0);
}
