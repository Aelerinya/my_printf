/*
** EPITECH PROJECT, 2018
** integer_conversions
** File description:
** Conversion specifiers for integers with management of length modifiers
*/

#include <stdarg.h>
#include <stdlib.h>
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

char *get_boux(va_list ap, char *modifier, char **str)
{
    switch (*modifier) {
    case 'l' :
        if (modifier[1] == 'l')
            return my_nbr_base(va_arg(ap, unsigned long long), get_base(str));
        else
            return my_nbr_base(va_arg(ap, unsigned long), get_base(str));
        break;
    case 'j' :
        return my_nbr_base(va_arg(ap, uintmax_t), get_base(str));
        break;
    case 'z' :
        return my_nbr_base(va_arg(ap, ssize_t), get_base(str));
        break;
    case 't' :
        return my_nbr_base(va_arg(ap, ptrdiff_t), get_base(str));
        break;
    default :
        return my_nbr_base(va_arg(ap, unsigned int), get_base(str));
    }
}

char *get_id(va_list ap, char *modifier)
{
    switch (*modifier) {
    case 'l' :
        if (modifier[1] == 'l')
            return my_nbr_to_str(va_arg(ap, long long));
        else
            return my_nbr_to_str(va_arg(ap, long));
        break;
    case 'j' :
        return my_nbr_to_str(va_arg(ap, intmax_t));
        break;
    case 'z' :
        return my_nbr_to_str(va_arg(ap, size_t));
        break;
    case 't' :
        return my_nbr_to_str(va_arg(ap, ptrdiff_t));
        break;
    default :
        return my_nbr_to_str(va_arg(ap, int));
    }
}

char *print_n(va_list ap, char *modifier, int *i)
{
    char *empty = malloc(sizeof(char));

    empty[0] = '\0';
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
    return empty;
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
