// Copyright, the authors of liba2i
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
static void test_leading_sign(void);
static void test_range(void);
static void test_trailing_text(void);


int
main(void)
{
	test_null();
	test_base();
	test_leading_text();
	test_leading_space();
	test_leading_sign();
	test_range();
	test_trailing_text();
}


static void
test_null(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2ull(&n, "x99z", NULL, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(a2ull(&n, "x99z", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "x99z") == 0);

	assert(a2ull(&n, "x99z", NULL, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(a2ull(&n, "x99z", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "x99z") == 0);

	assert(a2ull(&n, "99z", NULL, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(a2ull(&n, "99z", &e, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "z") == 0);

	assert(a2ull(&n, "9z", NULL, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(a2ull(&n, "9z", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, "z") == 0);

	errno = 0;

	assert(a2ull(&n, "9", NULL, 0, 7, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(a2ull(&n, "9", &e, 0, 7, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
}


static void
test_base(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2ull(&n, "9", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2ull(&n, "9", &e, -1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2ull(&n, "9", &e, -2, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2ull(&n, "9", &e, 37, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2ull(&n, "9", &e, 38, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2ull(&n, "9", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);

	assert(a2ull(&n, "", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "foo", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "foo") == 0);
	assert(a2ull(&n, "43", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "43") == 0);
	assert(a2ull(&n, "9", &e, 1, 42, 0) == -1);
	assert(n == 42);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2ull(&n, "9", &e, 1, 42, 0) == -1);
	assert(n == 42);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2ull(&n, "9foo", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9foo") == 0);

	errno = 0;

	assert(a2ull(&n, "11", &e, 0, 2, 42) == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 3, 2, 42) == 0);
	assert(n == 4);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 35, 2, 42) == 0);
	assert(n == 36);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 36, 2, 42) == 0);
	assert(n == 37);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2ull(&n, "0b11", &e, 0, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0B11", &e, 0, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "011", &e, 0, 2, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 0, 2, 42) == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0x11", &e, 0, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0X11", &e, 0, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2ull(&n, "011", &e, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0b11", NULL, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0B11", NULL, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "011", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0x11", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0X11", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2ull(&n, "011", &e, 7, 2, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 7, 2, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "011", &e, 8, 2, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "11", &e, 8, 2, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "z", &e, 36, 2, 42) == 0);
	assert(n == 35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "Z", &e, 36, 2, 42) == 0);
	assert(n == 35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
}


static void
test_leading_text(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2ull(&n, "", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "foo", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "foo") == 0);
	assert(a2ull(&n, "foo 7", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "foo 7") == 0);
	assert(a2ull(&n, "", &e, 0, 42, 0) == -1);
	assert(n == 42);
	assert(errno == ECANCELED);
	assert(strcmp(e, "") == 0);
}


static void
test_leading_space(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2ull(&n, " 9", &e, 0, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ECANCELED);
	assert(strcmp(e, " 9") == 0);
	assert(a2ull(&n, "\ta", &e, 16, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ECANCELED);
	assert(strcmp(e, "\ta") == 0);
	assert(a2ull(&n, "\n-a", &e, 16, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ECANCELED);
	assert(strcmp(e, "\n-a") == 0);
}


static void
test_leading_sign(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2ull(&n, "-1", &e, 0,,) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "-1") == 0);
	assert(a2ull(&n, "+1", &e, 0,,) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "+1") == 0);
	errno = 0;
	assert(a2ull(&n, "1", &e, 0,,) == 0);
	assert(n == 1);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
}


static void
test_range(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2ull(&n, "5", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "6", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "43", &e, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "44", &e, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2ull(&n, "7", &e, 0, 7, 4) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "42", &e, 0, 7, 4) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2ull(&n, "6z", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "z") == 0);
	assert(a2ull(&n, "6 ", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, " ") == 0);

	errno = 0;
	assert(a2ull(&n, "7", &e, 0, 7, 42) == 0);
	assert(n == 7);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "8", &e, 0, 7, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "41", &e, 0, 7, 42) == 0);
	assert(n == 41);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "42", &e, 0, 7, 42) == 0);
	assert(n == 42);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2ull(&n, "0xFFFFffffFFFFffff", &e, 0,,) == 0);
	assert(n == ULLONG_MAX);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2ull(&n, "0x1FFFFffffFFFFffff", &e, 0,,) == -1);
	assert(n == ULLONG_MAX);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
}


static void
test_trailing_text(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2ull(&n, "9 fff 7", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, " fff 7") == 0);
	assert(a2ull(&n, "9\t", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, "\t") == 0);
	assert(a2ull(&n, "9 ", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, " ") == 0);
}
