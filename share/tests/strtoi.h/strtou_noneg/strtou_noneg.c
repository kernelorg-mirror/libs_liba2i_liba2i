// SPDX-FileCopyrightText: 2024, Alejandro Colomar <alx@kernel.org>
// SPDX-License-Identifier: LGPL-3.0-only WITH LGPL-3.0-linking-exception


#include <a2i/strtoi.h>

#include <errno.h>
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
	int         s;
	const char  *e = "unmodified";

	errno = 0;

	assert(a2i_strtou_noneg("x99z", NULL, 1, 0, 42, NULL) == 0);
	assert(a2i_strtou_noneg("x99z", &e, 1, 0, 42, NULL) == 0);
	assert(a2i_strtou_noneg("x99z", NULL, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("x99z", &e, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);

	assert(strcmp(e, "unmodified") == 0);

	assert(a2i_strtou_noneg("x99z", NULL, 0, 0, 42, NULL) == 0);
	assert(a2i_strtou_noneg("x99z", &e, 0, 0, 42, NULL) == 0);
	assert(strcmp(e, "x99z") == 0);
	assert(a2i_strtou_noneg("x99z", NULL, 0, 0, 42, &s) == 0);
	assert(s == ECANCELED);
	assert(a2i_strtou_noneg("x99z", &e, 0, 0, 42, &s) == 0);
	assert(s == ECANCELED);
	assert(strcmp(e, "x99z") == 0);

	assert(a2i_strtou_noneg("99z", NULL, 0, 7, 42, NULL) == 42);
	assert(a2i_strtou_noneg("99z", &e, 0, 7, 42, NULL) == 42);
	assert(strcmp(e, "z") == 0);
	assert(a2i_strtou_noneg("99z", NULL, 0, 7, 42, &s) == 42);
	assert(s == ERANGE);
	assert(a2i_strtou_noneg("99z", &e, 0, 7, 42, &s) == 42);
	assert(s == ERANGE);
	assert(strcmp(e, "z") == 0);

	assert(a2i_strtou_noneg("9z", NULL, 0, 7, 42, NULL) == 9);
	assert(a2i_strtou_noneg("9z", &e, 0, 7, 42, NULL) == 9);
	assert(strcmp(e, "z") == 0);
	assert(a2i_strtou_noneg("9z", NULL, 0, 7, 42, &s) == 9);
	assert(s == ENOTSUP);
	assert(a2i_strtou_noneg("9z", &e, 0, 7, 42, &s) == 9);
	assert(s == ENOTSUP);
	assert(strcmp(e, "z") == 0);

	assert(a2i_strtou_noneg("9", NULL, 0, 7, 42, NULL) == 9);
	assert(a2i_strtou_noneg("9", &e, 0, 7, 42, NULL) == 9);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("9", NULL, 0, 7, 42, &s) == 9);
	assert(s == 0);
	assert(a2i_strtou_noneg("9", &e, 0, 7, 42, &s) == 9);
	assert(s == 0);
	assert(strcmp(e, "") == 0);

	assert(errno == 0);
}


static void
test_base(void)
{
	int         s;
	const char  *e = "unmodified";

	errno = 0;

	assert(a2i_strtou_noneg("9", &e, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9", &e, -1, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9", &e, -2, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9", &e, 37, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9", &e, 38, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9", &e, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);

	assert(a2i_strtou_noneg("", &e, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("foo", &e, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("43", &e, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9", &e, 1, 42, 0, &s) == 42);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9", &e, 1, 42, 0, &s) == 42);
	assert(s == EINVAL);
	assert(a2i_strtou_noneg("9foo", &e, 1, 0, 42, &s) == 0);
	assert(s == EINVAL);

	assert(strcmp(e, "unmodified") == 0);

	assert(a2i_strtou_noneg("11", &e, 0, 2, 42, &s) == 11);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 2, 2, 42, &s) == 3);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 3, 2, 42, &s) == 4);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 35, 2, 42, &s) == 36);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 36, 2, 42, &s) == 37);
	assert(s == 0);
	assert(strcmp(e, "") == 0);

	// Binary with "0b" depends on libc support.
	//assert(a2i_strtou_noneg("0b11", &e, 0, 2, 42, &s) == 3);
	//assert(s == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2i_strtou_noneg("0B11", &e, 0, 2, 42, &s) == 3);
	//assert(s == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2i_strtou_noneg("-0b11", &e, 0, 2, 42, &s) == 2);
	//assert(s == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2i_strtou_noneg("-0B11", &e, 0, 2, 42, &s) == 2);
	//assert(s == 0);
	//assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("011", &e, 0, 2, 42, &s) == 9);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-011", &e, 0, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 0, 2, 42, &s) == 11);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-11", &e, 0, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("0x11", &e, 0, 2, 42, &s) == 17);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("0X11", &e, 0, 2, 42, &s) == 17);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-0x11", &e, 0, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-0X11", &e, 0, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2i_strtou_noneg("011", &e, 2, 2, 42, &s) == 3);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 2, 2, 42, &s) == 3);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	//assert(a2i_strtou_noneg("0b11", NULL, 2, 2, 42, &s) == 3);
	//assert(s == 0);
	//assert(strcmp(e, "") == 0);
	//assert(a2i_strtou_noneg("0B11", NULL, 2, 2, 42, &s) == 3);
	//assert(s == 0);
	//assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-011", &e, 2, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-11", &e, 2, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	//assert(a2i_strtou_noneg("-0b11", NULL, 2, 2, 42, &s) == 2);
	//assert(s == ERANGE);
	//assert(strcmp(e, "") == 0);
	//assert(a2i_strtou_noneg("-0B11", NULL, 2, 2, 42, &s) == 2);
	//assert(s == ERANGE);
	//assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("011", &e, 16, 2, 42, &s) == 17);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 16, 2, 42, &s) == 17);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("0x11", &e, 16, 2, 42, &s) == 17);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("0X11", &e, 16, 2, 42, &s) == 17);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-011", &e, 16, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-11", &e, 16, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-0x11", &e, 16, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-0X11", &e, 16, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2i_strtou_noneg("011", &e, 7, 2, 42, &s) == 8);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 7, 2, 42, &s) == 8);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-011", &e, 7, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-11", &e, 7, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("011", &e, 8, 2, 42, &s) == 9);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("11", &e, 8, 2, 42, &s) == 9);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-011", &e, 8, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-11", &e, 8, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("z", &e, 36, 2, 42, &s) == 35);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("Z", &e, 36, 2, 42, &s) == 35);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-z", &e, 36, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-Z", &e, 36, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(errno == 0);
}


static void
test_leading_text(void)
{
	int         s;
	const char  *e;

	errno = 0;

	assert(a2i_strtou_noneg("", &e, 0, 0, 42, &s) == 0);
	assert(s == ECANCELED);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("foo", &e, 0, 0, 42, &s) == 0);
	assert(s == ECANCELED);
	assert(strcmp(e, "foo") == 0);
	assert(a2i_strtou_noneg("foo 7", &e, 0, 0, 42, &s) == 0);
	assert(s == ECANCELED);
	assert(strcmp(e, "foo 7") == 0);
	assert(a2i_strtou_noneg("", &e, 0, 42, 0, &s) == 42);
	assert(s == ECANCELED);
	assert(strcmp(e, "") == 0);

	assert(a2i_strtou_noneg(" 9", &e, 0, 2, 42, &s) == 9);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg(" \t\na", &e, 16, 2, 42, &s) == 10);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg(" \t\n-a", &e, 16, 2, 42, &s) == 2);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(errno == 0);
}


static void
test_range(void)
{
	int         s;
	const char  *e;

	errno = 0;

	assert(a2i_strtou_noneg("5", &e, 0, 7, 42, &s) == 7);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("6", &e, 0, 7, 42, &s) == 7);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("43", &e, 0, 7, 42, &s) == 42);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("44", &e, 0, 7, 42, &s) == 42);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2i_strtou_noneg("7", &e, 0, 7, 4, &s) == 7);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("42", &e, 0, 7, 4, &s) == 7);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(a2i_strtou_noneg("6z", &e, 0, 7, 42, &s) == 7);
	assert(s == ERANGE);
	assert(strcmp(e, "z") == 0);
	assert(a2i_strtou_noneg("6 ", &e, 0, 7, 42, &s) == 7);
	assert(s == ERANGE);
	assert(strcmp(e, " ") == 0);

	assert(a2i_strtou_noneg("7", &e, 0, 7, 42, &s) == 7);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("8", &e, 0, 7, 42, &s) == 8);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("41", &e, 0, 7, 42, &s) == 41);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("42", &e, 0, 7, 42, &s) == 42);
	assert(s == 0);
	assert(strcmp(e, "") == 0);

	assert(a2i_strtou_noneg("-1", &e, 0, 0, UINTMAX_MAX, &s) == 0);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("0xFFFFffffFFFFffff", &e, 0, 0, UINTMAX_MAX, &s) == UINTMAX_MAX);
	assert(s == 0);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-0xFFFFffffFFFFffff", &e, 0, 0, UINTMAX_MAX, &s) == 0);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("0xFFFFffffFFFFffff9", &e, 0, 0, UINTMAX_MAX, &s) == UINTMAX_MAX);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);
	assert(a2i_strtou_noneg("-0xFFFFffffFFFFffff9", &e, 0, 0, UINTMAX_MAX, &s) == 0);
	assert(s == ERANGE);
	assert(strcmp(e, "") == 0);

	assert(errno == 0);
}


static void
test_trailing_text(void)
{
	int         s;
	const char  *e;

	errno = 0;

	assert(a2i_strtou_noneg("\n9 fff 7", &e, 0, 7, 42, &s) == 9);
	assert(s == ENOTSUP);
	assert(strcmp(e, " fff 7") == 0);
	assert(a2i_strtou_noneg("\n9\t", &e, 0, 7, 42, &s) == 9);
	assert(s == ENOTSUP);
	assert(strcmp(e, "\t") == 0);
	assert(a2i_strtou_noneg("9 ", &e, 0, 7, 42, &s) == 9);
	assert(s == ENOTSUP);
	assert(strcmp(e, " ") == 0);

	assert(errno == 0);
}
