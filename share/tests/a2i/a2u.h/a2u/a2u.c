// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/a2i/a2u.h>

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
static void test_range(void);
static void test_trailing_text(void);


int
main(void)
{
	test_null();
	test_base();
	test_leading_text();
	test_range();
	test_trailing_text();
}


static void
test_null(void)
{
	const char    *e;
	unsigned int  n;

	assert(a2u(unsigned int, &n, "x99z", NULL, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(a2u(unsigned int, &n, "x99z", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "x99z") == 0);

	assert(a2u(unsigned int, &n, "x99z", NULL, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(a2u(unsigned int, &n, "x99z", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "x99z") == 0);

	assert(a2u(unsigned int, &n, "99z", NULL, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(a2u(unsigned int, &n, "99z", &e, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "z") == 0);

	assert(a2u(unsigned int, &n, "9z", NULL, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(a2u(unsigned int, &n, "9z", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, "z") == 0);

	errno = 0;

	assert(a2u(unsigned int, &n, "9", NULL, 0, 7, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(a2u(unsigned int, &n, "9", &e, 0, 7, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
}


static void
test_base(void)
{
	const char     *e;
	unsigned long  n;

	assert(a2u(unsigned long, &n, "9", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2u(unsigned long, &n, "9", &e, -1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2u(unsigned long, &n, "9", &e, -2, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2u(unsigned long, &n, "9", &e, 37, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2u(unsigned long, &n, "9", &e, 38, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2u(unsigned long, &n, "9", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);

	assert(a2u(unsigned long, &n, "", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "foo", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "foo") == 0);
	assert(a2u(unsigned long, &n, "43", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "43") == 0);
	assert(a2u(unsigned long, &n, "9", &e, 1, 42, 0) == -1);
	assert(n == 42);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2u(unsigned long, &n, "9", &e, 1, 42, 0) == -1);
	assert(n == 42);
	assert(errno == EINVAL);
	assert(strcmp(e, "9") == 0);
	assert(a2u(unsigned long, &n, "9foo", &e, 1, 0, 42) == -1);
	assert(n == 0);
	assert(errno == EINVAL);
	assert(strcmp(e, "9foo") == 0);

	errno = 0;

	assert(a2u(unsigned long, &n, "11", &e, 0, 2, 42) == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 3, 2, 42) == 0);
	assert(n == 4);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 35, 2, 42) == 0);
	assert(n == 36);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 36, 2, 42) == 0);
	assert(n == 37);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	// Binary with "0b" depends on libc support.
	//assert(a2u(unsigned long, &n, "0b11", &e, 0, 2, 42) == 0);
	//assertn == 3);
	//assert(errno == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2u(unsigned long, &n, "0B11", &e, 0, 2, 42) == 0);
	//assertn == 3);
	//assert(errno == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2u(unsigned long, &n, "-0b11", &e, 0, 2, 42) == 0);
	//assertn == 2);
	//assert(errno == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2u(unsigned long, &n, "-0B11", &e, 0, 2, 42) == 0);
	//assertn == 2);
	//assert(errno == 0);
	//assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "011", &e, 0, 2, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-011", &e, 0, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	errno = 0;
	assert(a2u(unsigned long, &n, "11", &e, 0, 2, 42) == 0);
	assert(n == 11);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-11", &e, 0, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	errno = 0;
	assert(a2u(unsigned long, &n, "0x11", &e, 0, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "0X11", &e, 0, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-0x11", &e, 0, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-0X11", &e, 0, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	errno = 0;
	assert(a2u(unsigned long, &n, "011", &e, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 2, 2, 42) == 0);
	assert(n == 3);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	//assert(a2u(unsigned long, &n, "0b11", NULL, 2, 2, 42) == 0);
	//assertn == 3);
	//assert(errno == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2u(unsigned long, &n, "0B11", NULL, 2, 2, 42) == 0);
	//assertn == 3);
	//assert(errno == 0);
	//assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-011", &e, 2, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-11", &e, 2, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	//assert(a2u(unsigned long, &n, "-0b11", NULL, 2, 2, 42) == -1);
	//assertn == 2);
	//assert(errno == ERANGE);
	//assert(strcmp(e, "") == 0);
	//assert(a2u(unsigned long, &n, "-0B11", NULL, 2, 2, 42) == -1);
	//assertn == 2);
	//assert(errno == ERANGE);
	//assert(strcmp(e, "") == 0);
	errno = 0;
	assert(a2u(unsigned long, &n, "011", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "0x11", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "0X11", &e, 16, 2, 42) == 0);
	assert(n == 17);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-011", &e, 16, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-11", &e, 16, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-0x11", &e, 16, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-0X11", &e, 16, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	errno = 0;
	assert(a2u(unsigned long, &n, "011", &e, 7, 2, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 7, 2, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-011", &e, 7, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-11", &e, 7, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	errno = 0;
	assert(a2u(unsigned long, &n, "011", &e, 8, 2, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "11", &e, 8, 2, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-011", &e, 8, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-11", &e, 8, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	errno = 0;
	assert(a2u(unsigned long, &n, "z", &e, 36, 2, 42) == 0);
	assert(n == 35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "Z", &e, 36, 2, 42) == 0);
	assert(n == 35);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-z", &e, 36, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long, &n, "-Z", &e, 36, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
}


static void
test_leading_text(void)
{
	const char          *e;
	unsigned long long  n;

	assert(a2u(unsigned long long, &n, "", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long long, &n, "foo", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "foo") == 0);
	assert(a2u(unsigned long long, &n, "foo 7", &e, 0, 0, 42) == -1);
	assert(n == 0);
	assert(errno == ECANCELED);
	assert(strcmp(e, "foo 7") == 0);
	assert(a2u(unsigned long long, &n, "", &e, 0, 42, 0) == -1);
	assert(n == 42);
	assert(errno == ECANCELED);
	assert(strcmp(e, "") == 0);

	errno = 0;

	assert(a2u(unsigned long long, &n, " 9", &e, 0, 2, 42) == 0);
	assert(n == 9);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long long, &n, " \t\na", &e, 16, 2, 42) == 0);
	assert(n == 10);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned long long, &n, " \t\n-a", &e, 16, 2, 42) == -1);
	assert(n == 2);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
}


static void
test_range(void)
{
	const char     *e;
	unsigned char  n;

	assert(a2u(unsigned char, &n, "5", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "6", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "43", &e, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "44", &e, 0, 7, 42) == -1);
	assert(n == 42);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2u(unsigned char, &n, "7", &e, 0, 7, 4) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "42", &e, 0, 7, 4) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2u(unsigned char, &n, "6z", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, "z") == 0);
	assert(a2u(unsigned char, &n, "6 ", &e, 0, 7, 42) == -1);
	assert(n == 7);
	assert(errno == ERANGE);
	assert(strcmp(e, " ") == 0);

	errno = 0;
	assert(a2u(unsigned char, &n, "7", &e, 0, 7, 42) == 0);
	assert(n == 7);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "8", &e, 0, 7, 42) == 0);
	assert(n == 8);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "41", &e, 0, 7, 42) == 0);
	assert(n == 41);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "42", &e, 0, 7, 42) == 0);
	assert(n == 42);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);

	assert(a2u(unsigned char, &n, "-1", &e, 0, 0, UCHAR_MAX) == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	errno = 0;
	assert(a2u(unsigned char, &n, "0xFF", &e, 0, 0, UCHAR_MAX) == 0);
	assert(n == 0xFF);
	assert(errno == 0);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "-0xFF", &e, 0, 0, UCHAR_MAX) == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "0xFF9", &e, 0, 0, UCHAR_MAX) == -1);
	assert(n == UCHAR_MAX);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2u(unsigned char, &n, "-0xFF9", &e, 0, 0, UCHAR_MAX) == -1);
	assert(n == 0);
	assert(errno == ERANGE);
	assert(strcmp(e, "") == 0);
}


static void
test_trailing_text(void)
{
	const char      *e;
	unsigned short  n;

	assert(a2u(unsigned short, &n, "\n9 fff 7", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, " fff 7") == 0);
	assert(a2u(unsigned short, &n, "\n9\t", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, "\t") == 0);
	assert(a2u(unsigned short, &n, "9 ", &e, 0, 7, 42) == -1);
	assert(n == 9);
	assert(errno == ENOTSUP);
	assert(strcmp(e, " ") == 0);
}
