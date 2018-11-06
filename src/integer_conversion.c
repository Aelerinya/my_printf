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
    if (modifier[0] == 'h' && modifier[1] == 'h')
        my_putnbr_base((unsigned char)va_arg(ap, unsigned int), get_base(str), i);
    else if (modifier[0] == 'h')
        my_putnbr_base((unsigned short)va_arg(ap, unsigned int), get_base(str), i);
    if (modifier[0] == 'l' && modifier[1] == 'l')
        my_putnbr_base(va_arg(ap, unsigned long long), get_base(str), i);
    else if (modifier[0] == 'l')
        my_putnbr_base(va_arg(ap, unsigned long), get_base(str), i);
    if (modifier[0] == 'j')
        my_putnbr_base(va_arg(ap, uintmax_t), get_base(str), i);
    if (modifier[0] == 'z')
        my_putnbr_base(va_arg(ap, ssize_t), get_base(str), i);
    if (modifier[0] == 't')
        my_putnbr_base(va_arg(ap, ptrdiff_t), get_base(str), i);
    if (modifier[0] == '\0')
        my_putnbr_base(va_arg(ap, unsigned int), get_base(str), i);
}

void print_idn(va_list ap, char *modifier, char **str, int *i)
{
    int *ptr;

    if (**str == 'n') {
        ptr = va_arg(ap, int *);
        *ptr = *i;
    } else
        my_put_nbr(va_arg(ap, int), i);
}
