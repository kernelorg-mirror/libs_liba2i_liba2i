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


static void test_base(void);
static void test_leading_text(void);
static void test_leading_space(void);
static void test_leading_sign(void);
static void test_range(void);
static void test_trailing_text(void);


int
main(void)
{
	test_base();
	test_leading_text();
	test_leading_space();
	test_leading_sign();
	test_range();
	test_trailing_text();
}


static void
test_base(void)
{
	unsigned long long  n;

	errno = 0;

	assert(str2ull(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);

	assert(str2ull(&n, "0b11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2ull(&n, "0B11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2ull(&n, "011") == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(str2ull(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(str2ull(&n, "0x11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2ull(&n, "0X11") == 0);
	assert(n == 17);
	assert(errno == 0);
}


static void
test_leading_text(void)
{
	unsigned long long  n;

	assert(str2ull(&n, "") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ull(&n, "foo") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ull(&n, "foo 7") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_leading_space(void)
{
	unsigned long long  n;

	assert(str2ull(&n, " 9") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ull(&n, " \t\n0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ull(&n, " \t\n-0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_leading_sign(void)
{
	unsigned long long  n;

	assert(str2ull(&n, "-1") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ull(&n, "+1") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	errno = 0;
	assert(str2ull(&n, "1") == 0);
	assert(n == 1);
	assert(errno == 0);
}


static void
test_range(void)
{
	unsigned long long  n;

	errno = 0;

	assert(str2ull(&n, "0xFFFFffffFFFFffff") == 0);
	assert(n == ULLONG_MAX);
	assert(errno == 0);
	assert(str2ull(&n, "0x1FFFFffffFFFFffff") == -1);
	assert(n == ULLONG_MAX);
	assert(errno == ERANGE);
}


static void
test_trailing_text(void)
{
	unsigned long long  n;

	assert(str2ull(&n, "9 fff 7") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2ull(&n, "9\t") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2ull(&n, "9 ") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
}
