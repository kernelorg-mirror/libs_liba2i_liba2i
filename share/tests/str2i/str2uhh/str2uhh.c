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
	unsigned char  n;

	errno = 0;

	assert(str2uhh(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);

	assert(str2uhh(&n, "0b11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2uhh(&n, "0B11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2uhh(&n, "-0b11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2uhh(&n, "-0B11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2uhh(&n, "011") == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(str2uhh(&n, "-011") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2uhh(&n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(str2uhh(&n, "-11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2uhh(&n, "0x11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2uhh(&n, "0X11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2uhh(&n, "-0x11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	assert(str2uhh(&n, "-0X11") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
}


static void
test_leading_text(void)
{
	unsigned char  n;

	assert(str2uhh(&n, "") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2uhh(&n, "foo") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2uhh(&n, "foo 7") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);

	errno = 0;

	assert(str2uhh(&n, " 9") == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(str2uhh(&n, " \t\n0xa") == 0);
	assert(n == 10);
	assert(errno == 0);
	assert(str2uhh(&n, " \t\n-0xa") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
}


static void
test_range(void)
{
	unsigned char  n;

	assert(str2uhh(&n, "-1") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	errno = 0;
	assert(str2uhh(&n, "0xFF") == 0);
	assert(n == 0xFF);
	assert(errno == 0);
	assert(str2uhh(&n, "-0xFF") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	assert(str2uhh(&n, "0x1FF") == -1);
	assert(n == UCHAR_MAX);
	assert(errno == ERANGE);
	assert(str2uhh(&n, "-0x1FF") == -1);
	assert(n == 0);
	assert(errno == ERANGE);
}


static void
test_trailing_text(void)
{
	unsigned char  n;

	assert(str2uhh(&n, "\n9 fff 7") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2uhh(&n, "\n9\t") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2uhh(&n, "9 ") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
}
