/*
** EPITECH PROJECT, 2018
** integer_conversions
** File description:
** Conversion specifiers for integers with management of length modifiers
*/

#include <stdarg.h>
#include <stdio.h>
#include <inttypes.h>
#include <stddef.h>
#include "header.h"

static char *get_base(char **str)
{
    if (**str == 'b')
        return "01";
    if (**str == 'o')
        return "01234567";
    if (**str == 'x')
        return "0123456789abcdef";
    if (**str == 'X')
        return "0123456789ABCDEF";
    return "0123456789";
}

void print_boux(va_list ap, char *modifier, char **str, int *i)
{
    switch (*modifier) {
    case 'l' :
        if (modifier[1] == 'l')
            my_putnbr_base(va_arg(ap, unsigned long long), get_base(str), i);
        else
            my_putnbr_base(va_arg(ap, unsigned long), get_base(str), i);
        break;
    case 'j' :
        my_putnbr_base(va_arg(ap, uintmax_t), get_base(str), i);
        break;
    case 'z' :
        my_putnbr_base(va_arg(ap, ssize_t), get_base(str), i);
        break;
    case 't' :
        my_putnbr_base(va_arg(ap, ptrdiff_t), get_base(str), i);
        break;
    default :
        my_putnbr_base(va_arg(ap, unsigned int), get_base(str), i);
    }
}

void print_id(va_list ap, char *modifier, int *i)
{
    switch (*modifier) {
    case 'l' :
        if (modifier[1] == 'l')
            my_put_nbr(va_arg(ap, long long), i);
        else
            my_put_nbr(va_arg(ap, long), i);
        break;
    case 'j' :
        my_put_nbr(va_arg(ap, intmax_t), i);
        break;
    case 'z' :
        my_put_nbr(va_arg(ap, size_t), i);
        break;
    case 't' :
        my_put_nbr(va_arg(ap, ptrdiff_t), i);
        break;
    default :
        my_put_nbr(va_arg(ap, int), i);
    }
}

void print_n(va_list ap, char *modifier, int *i)
{
    switch (*modifier) {
    case 'h' :
        if (modifier[1] == 'h')
            va_arg(ap, char *)[0] = *i;
        else
            va_arg(ap, short *)[0] = *i;
        break;
    case 'l' :
        if (modifier[1] == 'l')
            va_arg(ap, long long *)[0] = *i;
        else
            va_arg(ap, long *)[0] = *i;
        break;
    default :
        print_n2(ap, modifier, i);
    }
}

void print_n2(va_list ap, char *modifier, int *i)
{
    switch (*modifier) {
    case 'j' :
        va_arg(ap, intmax_t *)[0] = *i;
        break;
    case 'z' :
        va_arg(ap, size_t *)[0] = *i;
        break;
    case 't' :
        va_arg(ap, ptrdiff_t *)[0] = *i;
        break;
    default :
        va_arg(ap, int *)[0] = *i;
    }
}
