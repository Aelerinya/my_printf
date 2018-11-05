/*
** EPITECH PROJECT, 2018
** test_conversion_specifiers
** File description:
** Tests for the conversion specifiers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(conversion_specifiers, normal, .init = redirect)
{
    char str[4] = "b\na";
    char *format = "%%%s%S%i%i%i%d%b%o%u%x%Xl";
    char *result = "%ab\\012\\177-214748364802147483647-4101112f1Fl";
    int i = 2147483647;
    int j = -2147483648;

    str[2] = 127;
    my_printf(format, "a", str, j, 0, i, -4, 2, 9, 12, 15, 31);
    cr_assert_stdout_eq_str(result);
}
