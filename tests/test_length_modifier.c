/*
** EPITECH PROJECT, 2018
** tests_length_modifier
** File description:
** Criterion unit tests for length modifiers
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include "header.h"

void redirect(void);

Test(length_modifiers, unsigned_conversion, .init = redirect)
{
    char *format = "%hhu %hu %u %lu %llu %ju %zu %tu";
    char *theory = "5 300 70000 3000000000 0 3 3 3";

    my_printf(format, 5, 300, 70000, 3000000000, 0, 3, 3, 3);
    fflush(stdout);
    cr_assert_stdout_eq_str(theory);
}

Test(length_modifier, signed_conversion, .init = redirect)
{
    char *format = "%hhi %hd %i %ld %lli %jd %zi %td";
    char *theory = "-5 200 -40000 1000000000 0 3 3 3";

    my_printf(format, -5, 200, -40000, 1000000000, 0, 3, 3, 3);
    fflush(stdout);
    cr_assert_stdout_eq_str(theory);
}

Test(length_modifier, n, .init = redirect)
{
    char *length = "abc%hhn%hn%n%ln%lln%jn%zn%tn";
    char hhn[1];
    short hn[1];
    int n[1];
    long ln[1];
    long long lln[1];
    size_t zn[1];
    intmax_t jn[1];
    ptrdiff_t tn[1];

    my_printf(length, hhn, hn, n, ln, lln, jn, zn, tn);
    cr_assert_eq(*hhn, 3);
    cr_assert_eq(*hn, 3);
    cr_assert_eq(*n, 3);
    cr_assert_eq(*ln, 3);
    cr_assert_eq(*lln, 3);
    cr_assert_eq(*zn, 3);
    cr_assert_eq(*jn, 3);
    cr_assert_eq(*tn, 3);
}
