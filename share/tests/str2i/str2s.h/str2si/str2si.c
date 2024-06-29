// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/str2i/str2s.h>

#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>


static void test_base(void);
static void test_leading_text(void);
static void test_range(void);
static void test_trailing_text(void);


int
main(void)
{
	test_base();
	test_leading_text();
	test_range();
	test_trailing_text();
}


static void
test_base(void)
{
	int  n;

	errno = 0;

	assert(str2si(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);

	// Binary with "0b" depends on libc support.
	//assert(str2si(&n, "0b11") == 0);
	//assertn == 3);
	//assert(errno == 0);
	//assert(str2si(&n, "0B11") == 0);
	//assertn == 3);
	//assert(errno == 0);
	//assert(str2si(&n, "-0b11") == 0);
	//assertn == -3);
	//assert(errno == 0);
	//assert(str2si(&n, "-0B11") == 0);
	//assertn == -3);
	//assert(errno == 0);
	assert(str2si(&n, "011") == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(str2si(&n, "-011") == 0);
	assert(n == -9);
	assert(errno == 0);
	assert(str2si(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(str2si(&n, "-11") == 0);
	assert(n == -11);
	assert(errno == 0);
	assert(str2si(&n, "0x11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2si(&n, "0X11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2si(&n, "-0x11") == 0);
	assert(n == -17);
	assert(errno == 0);
	assert(str2si(&n, "-0X11") == 0);
	assert(n == -17);
	assert(errno == 0);
}


static void
test_leading_text(void)
{
	int  n;

	assert(str2si(&n, "") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2si(&n, "foo") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2si(&n, "foo 7") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);

	errno = 0;

	assert(str2si(&n, " 1") == 0);
	assert(n == 1);
	assert(errno == 0);
	assert(str2si(&n, " \t\n0xa") == 0);
	assert(n == 10);
	assert(errno == 0);
	assert(str2si(&n, " \t\n-0xa") == 0);
	assert(n == -10);
	assert(errno == 0);
}


static void
test_range(void)
{
	int  n;

	assert(str2si(&n, "-1") == 0);
	assert(n == -1);
	assert(errno == 0);
	assert(str2si(&n, "0xFFF") == 0);
	assert(n == 0xFFF);
	assert(errno == 0);
	assert(str2si(&n, "0xFFFFffffFFFFffff") == -1);
	assert(n == INT_MAX);
	assert(errno == ERANGE);
	assert(str2si(&n, "-0xFFFFffffFFFFffff") == -1);
	assert(n == INT_MIN);
	assert(errno == ERANGE);
}


static void
test_trailing_text(void)
{
	int  n;

	assert(str2si(&n, "\n9 fff 7") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2si(&n, "\n9\t") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2si(&n, "9 ") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
}
