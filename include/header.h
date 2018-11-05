/*
** EPITECH PROJECT, 2018
** my_printf header
** File description:
** Main header for the my_printf project
*/

#include <stdarg.h>

int my_printf(const char *format, ...);
int my_putstr(char const *str);
void my_putchar(char c);
void print_data(va_list ap, char *str);
int my_put_nbr(int nb);
int my_putnbr_base(unsigned int nbr, char const *base);
int my_showstr(char const *str);
void my_putptr(void *ptr);
