// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/a2i.h>

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
	unsigned int  n;

	errno = 0;

	assert(str2ui(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);

	assert(str2ui(&n, "0b11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2ui(&n, "0B11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2ui(&n, "-0b11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2ui(&n, "-0B11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2ui(&n, "011") == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(str2ui(&n, "-011") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2ui(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(str2ui(&n, "-11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2ui(&n, "0x11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2ui(&n, "0X11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2ui(&n, "-0x11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	assert(str2ui(&n, "-0X11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
}


static void
test_leading_text(void)
{
	unsigned int  n;

	assert(str2ui(&n, "") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ui(&n, "foo") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ui(&n, "foo 7") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_leading_space(void)
{
	unsigned int  n;

	assert(str2ui(&n, " 9") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ui(&n, "\t0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2ui(&n, "\n-0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_range(void)
{
	unsigned int  n;

	errno = 0;

	assert(str2ui(&n, "-1") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2ui(&n, "0xFFFFffff") == 0);
	assert(n == 0xFFFFffff);
	assert(errno == 0);
	assert(str2ui(&n, "-0xFFFFffff") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	assert(str2ui(&n, "0x1FFFFffffFFFFffff") == -1);
	assert(n == UINT_MAX);
	assert(errno == ERANGE);
	assert(str2ui(&n, "-0x1FFFFffffFFFFffff") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
}


static void
test_trailing_text(void)
{
	unsigned int  n;

	assert(str2ui(&n, "9 fff 7") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2ui(&n, "9\t") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2ui(&n, "9 ") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
}
