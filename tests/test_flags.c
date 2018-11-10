/*
** EPITECH PROJECT, 2018
** test_flags
** File description:
** Criterion unit tests for my_printf flags
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>
#include "header.h"

void redirect(void);

Test(flag, alternate, .init = redirect)
{
    my_printf("%#x %#X %#o %#o %#o %#i", 15, 0, 9, 0, 1, 3);
    cr_assert_stdout_eq_str("0xf 0X0 011 0 01 3");
}

Test(flag, getflags)
{
    char *str = "#0- +30.i";
    char *str2 = ".-4";
    va_list ap;
    flags_t *flags = get_flags(&str, ap);

    cr_assert_eq(flags->alternate, 1);
    cr_assert_eq(flags->zero_padding, 1);
    cr_assert_eq(flags->field_width, 30);
    cr_assert_eq(flags->left_adjusting, 1);
    cr_assert_eq(flags->precision, 0);
    cr_assert_eq(flags->space, 1);
    cr_assert_eq(flags->force_sign, 1);
    free(flags);
    flags = get_flags(&str2, ap);
    cr_assert_eq(flags->precision, -1);
    free(flags);
}

Test(flag, invalid_syntax, .init = redirect)
{
    my_printf("%.#i", 3);
    cr_assert_stdout_eq_str("%.#i");
}

Test(flag, signed_conversions, .init = redirect)
{
    my_printf("%+i % i %+ d % i %+i", 5, 3, 0, -1, -666);
    cr_assert_stdout_eq_str("+5  3 +0 -1 -666");
}

Test(flag, precision, .init = redirect)
{
    char *format = "%.2s %.2s %.4S %.2S %.x%.i%.2b %.2b %.2i %.2i";

    my_printf(format, "abc", "a", "\n", "\n", 0, 0, 3, 1, 23, 3);
    cr_assert_stdout_eq_str("ab a \\012 \\0 11 01 23 03");
}
