/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** My_printf is an implementation of the printf function
** according to the C99 standard
*/

#include <stdarg.h>
#include <stdlib.h>
#include "header.h"

int my_printf(const char *format, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, format);
    for (char *str = (char *)format; *str != '\0'; str++) {
        if (*str == '%') {
            str++;
            modifier(ap, &str, &i);
        }
        else
            i++, my_putchar(*str);
    }
    va_end(ap);
    return (i);
}

void modifier(va_list ap, char **str, int *i)
{
    va_list copy;

    if (**str == '#') {
        if ((*str)[1] == 'x')
            my_putstr("0x", i);
        if ((*str)[1] == 'X')
            my_putstr("0X", i);
        if ((*str)[1] == 'o') {
            va_copy(copy, ap);
            if (va_arg(copy, unsigned int) != 0)
                my_putstr("0", i);
            va_end(copy);
        }
        (*str)++;
    }
    print_data(ap, str, i);
}

char *get_length_modifier(char **str)
{
    char *modifier;

    modifier = malloc(sizeof(char) * 3);
    for (int i = 0; i < 3; modifier[i++] = '\0');
    if (**str == 'j' || **str == 'z' || **str == 't')
        modifier[0] = **str, (*str)++;
    else if (**str == 'h' || **str == 'l') {
        modifier[0] = **str, (*str)++;
        if (**str == 'h' || **str == 'l')
            modifier[1] = **str, (*str)++;
    }
    return modifier;
}

void print_data(va_list ap, char **str, int *i)
{
    char *modifier;

    if (**str == '%' || **str == 'c')
        (*i)++, my_putchar((**str == 'c') ? va_arg(ap, unsigned int) : '%');
    if (**str == 'p')
        my_putptr(va_arg(ap, void *), i);
    if (**str == 's')
        my_putstr(va_arg(ap, char *), i);
    if (**str == 'S')
        my_showstr(va_arg(ap, char *), i);
    modifier = get_length_modifier(str);
    if (**str == 'i' || **str == 'd')
        print_id(ap, modifier, i);
    if (**str == 'b' || **str == 'o' || **str == 'u'
    || **str == 'x' || **str == 'X')
        print_boux(ap, modifier, str, i);
    if (**str == 'n')
        print_n(ap, modifier, i);
}
