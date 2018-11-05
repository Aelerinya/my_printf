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
    char *format = "%%%s%S%i%i%i%d%b%o%u%x%Xl%p%c";
    char *result = "%ab\\012\\177-214748364802147483647-4101112f1Fl0x2fM";
    void *ptr = (void *)47;
    int i = 2147483647;
    int j = -2147483648;

    str[2] = 127;
    my_printf(format, "a", str, j, 0, i, -4, 2, 9, 12, 15, 31, ptr, 'M');
    cr_assert_stdout_eq_str(result);
}

Test(conversion_specifiers, length, .init = redirect)
{
    char str[4] = "b\na";
    char *format = "%%%s%S%i%i%i%d%b%o%u%x%Xl%p%c";
    char *result = "%ab\\012\\177-214748364802147483647-4101112f1Fl0x2fM";
    void *ptr = (void *)47;
    int i = 2147483647;
    int j = -2147483648;
    int size;
    int result_size;

    for (size = 0; result[size] != '\0'; size++);
    str[2] = 127;
    result_size = my_printf(format, "a", str, j, 0, i, -4, 2, 9, 12, 15, 31, ptr, 'M');
    cr_assert_eq(result_size, size);
}

Test(flag, alternate, .init = redirect)
{
    my_printf("%#x %#X %#o %#o", 15, 0, 9, 0);
    cr_assert_stdout_eq_str("0xf 0X0 011 0");
}
