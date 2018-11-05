/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** My_printf is an implementation of the printf function
** according to the C99 standard
*/

#include <stdarg.h>
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

void print_data(va_list ap, char **str, int *i)
{
    if (**str == 's')
        my_putstr(va_arg(ap, char *), i);
    if (**str == 'S')
        my_showstr(va_arg(ap, char *), i);
    if (**str == 'i' || **str == 'd')
        my_put_nbr(va_arg(ap, int), i);
    if (**str == 'b')
        my_putnbr_base(va_arg(ap, unsigned int), "01", i);
    if (**str == 'o')
        my_putnbr_base(va_arg(ap, unsigned int), "01234567", i);
    if (**str == 'u')
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789", i);
    if (**str == 'x')
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", i);
    if (**str == 'X')
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", i);
    if (**str == 'p')
        my_putptr(va_arg(ap, void *), i);
    if (**str == '%' || **str == 'c')
        (*i)++, my_putchar((**str == 'c') ? va_arg(ap, unsigned int) : '%');
}
