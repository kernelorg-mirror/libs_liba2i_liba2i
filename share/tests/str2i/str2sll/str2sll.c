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
static void test_range(void);
static void test_trailing_text(void);


int
main(void)
{
	test_base();
	test_leading_text();
	test_leading_space();
	test_range();
	test_trailing_text();
}


static void
test_base(void)
{
	long long  n;

	errno = 0;

	assert(str2sll(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);

	assert(str2sll(&n, "0b11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2sll(&n, "0B11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2sll(&n, "-0b11") == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(str2sll(&n, "-0B11") == 0);
	assert(n == -3);
	assert(errno == 0);
	assert(str2sll(&n, "011") == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(str2sll(&n, "-011") == 0);
	assert(n == -9);
	assert(errno == 0);
	assert(str2sll(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(str2sll(&n, "-11") == 0);
	assert(n == -11);
	assert(errno == 0);
	assert(str2sll(&n, "0x11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2sll(&n, "0X11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2sll(&n, "-0x11") == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(str2sll(&n, "-0X11") == 0);
	assert(n == -17);
	assert(errno == 0);
}


static void
test_leading_text(void)
{
	long long  n;

	assert(str2sll(&n, "") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2sll(&n, "foo") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2sll(&n, "foo 7") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_leading_space(void)
{
	long long  n;

	assert(str2sll(&n, " 1") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2sll(&n, "\t0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2sll(&n, "\n-0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_range(void)
{
	long long  n;

	errno = 0;

	assert(str2sll(&n, "-1") == 0);
	assert(n == -1);
	assert(errno == 0);
	assert(str2sll(&n, "0x7FFFffffFFFFffff") == 0);
	assert(n == 0x7FFFffffFFFFffff);
	assert(errno == 0);
	assert(str2sll(&n, "-0x8000000000000000") == 0);
	assert(n == LLONG_MIN);
	assert(errno == 0);
	assert(str2sll(&n, "0xFFFFffffFFFFffff") == -1);
	assert(n == LLONG_MAX);
	assert(errno == ERANGE);
	assert(str2sll(&n, "-0xFFFFffffFFFFffff") == -1);
	assert(n == LLONG_MIN);
	assert(errno == ERANGE);
}


static void
test_trailing_text(void)
{
	long long  n;

	assert(str2sll(&n, "9 fff 7") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2sll(&n, "9\t") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2sll(&n, "9 ") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
}
