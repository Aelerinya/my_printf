/*
** EPITECH PROJECT, 2018
** test_flags2
** File description:
** Criterion unit tests for my_printf flags, part 2
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>
#include "header.h"

void redirect(void);

Test(flag, field_width, .init = redirect)
{
    my_printf("%-3i|%3i", 2, 2);
    cr_assert_stdout_eq_str("2  |  2");
}

Test(flag, zero_padding, .init = redirect)
{
    my_printf("%0-3i|%03i|%#05x|%05X|%03s|%#05.2x", 2, 2, 11, 11, "a", 11);
    cr_assert_stdout_eq_str("2  |002|0x00b|0000B|  a| 0x0b");
}

Test(flag, star_char, .init = redirect)
{
    my_printf("%*x|%.*x", 3, 11, 3, 11);
    cr_assert_stdout_eq_str("  b|00b");
}
