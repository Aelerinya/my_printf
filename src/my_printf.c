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
    char *str = (char *)format;

    va_start(ap, format);
    for (int i = 0; *str != '\0'; i++, str++) {
        if (*str == '%')
            print_data(ap, ++str);
        else
            my_putchar(*str);
    }
    va_end(ap);
    return (0);
}

void print_data(va_list ap, char *str)
{
    if (*str == 's')
        my_putstr(va_arg(ap, char *));
    if (*str == 'S')
        my_showstr(va_arg(ap, char *));
    if (*str == 'i' || *str == 'd')
        my_put_nbr(va_arg(ap, int));
    if (*str == 'b')
        my_putnbr_base(va_arg(ap, unsigned int), "01");
    if (*str == 'o')
        my_putnbr_base(va_arg(ap, unsigned int), "01234567");
    if (*str == 'u')
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789");
    if (*str == 'x')
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
    if (*str == 'X')
        my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
    if (*str == '%')
        my_putchar('%');
}
