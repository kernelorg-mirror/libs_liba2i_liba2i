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
	unsigned int  n;

	errno = 0;

	assert(str2i(unsigned int, &n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);

	assert(str2i(unsigned int, &n, "0b11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2i(unsigned int, &n, "0B11") == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(str2i(unsigned int, &n, "011") == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(str2i(unsigned int, &n, "11") == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(str2i(unsigned int, &n, "0x11") == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(str2i(unsigned int, &n, "0X11") == 0);
	assert(n == 17);
	assert(errno == 0);
}


static void
test_leading_text(void)
{
	long long  n;

	assert(str2i(long long, &n, "") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2i(long long, &n, "foo") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2i(long long, &n, "foo 7") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_leading_space(void)
{
	long long  n;

	assert(str2i(long long, &n, " 1") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2i(long long, &n, "\t0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2i(long long, &n, "\n-0xa") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
}


static void
test_leading_sign(void)
{
	unsigned char  n;

	assert(str2i(unsigned char, &n, "-1") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(str2i(unsigned char, &n, "+1") == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	errno = 0;
	assert(str2i(unsigned char, &n, "1") == 0);
	assert(n == 1);
	assert(errno == 0);
}


static void
test_range(void)
{
	unsigned char  n;

	errno = 0;

	assert(str2i(unsigned char, &n, "0xFF") == 0);
	assert(n == 0xFF);
	assert(errno == 0);
	assert(str2i(unsigned char, &n, "0x1FF") == -1);
	assert(n == UCHAR_MAX);
	assert(errno == ERANGE);
}


static void
test_trailing_text(void)
{
	short  n;

	assert(str2i(short, &n, "9 fff 7") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2i(short, &n, "9\t") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(str2i(short, &n, "9 ") == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
}
