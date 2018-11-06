/*
** EPITECH PROJECT, 2018
** my_printf header
** File description:
** Main header for the my_printf project
*/

#include <stdarg.h>

int my_printf(const char *format, ...);
int my_putstr(char const *str, int *i);
void my_putchar(char c);
int my_put_nbr(long long int nb, int *i);
int my_putnbr_base(unsigned long long int nbr, char const *base, int *i);
int my_showstr(char const *str, int *i);
void my_putptr(void *ptr, int *i);

void print_data(va_list ap, char **str, int *i);
void modifier(va_list ap, char **str, int *i);
char *get_length_modifier(char **str);

void print_boux(va_list ap, char *modifier, char **str, int *i);
void print_idn(va_list ap, char *modifier, char **str, int *i);
