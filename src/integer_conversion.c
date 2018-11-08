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

static char *b(char **str)
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

char *get_boux(va_list ap, char *modifier, char **str, flags_t *flags)
{
    switch (*modifier) {
    case 'l' :
        if (modifier[1] == 'l')
            return my_nbr_base(va_arg(ap, unsigned long long), b(str), flags);
        else
            return my_nbr_base(va_arg(ap, unsigned long), b(str), flags);
        break;
    case 'j' :
        return my_nbr_base(va_arg(ap, uintmax_t), b(str), flags);
        break;
    case 'z' :
        return my_nbr_base(va_arg(ap, ssize_t), b(str), flags);
        break;
    case 't' :
        return my_nbr_base(va_arg(ap, ptrdiff_t), b(str), flags);
        break;
    default :
        return my_nbr_base(va_arg(ap, unsigned int), b(str), flags);
    }
}

char *get_id(va_list ap, char *modifier, flags_t *flags)
{
    switch (*modifier) {
    case 'l' :
        if (modifier[1] == 'l')
            return my_nbr_to_str(va_arg(ap, long long), flags);
        else
            return my_nbr_to_str(va_arg(ap, long), flags);
        break;
    case 'j' :
        return my_nbr_to_str(va_arg(ap, intmax_t), flags);
        break;
    case 'z' :
        return my_nbr_to_str(va_arg(ap, size_t), flags);
        break;
    case 't' :
        return my_nbr_to_str(va_arg(ap, ptrdiff_t), flags);
        break;
    default :
        return my_nbr_to_str(va_arg(ap, int), flags);
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
