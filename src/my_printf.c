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
        if (*str == '%' && str[1] == '%')
            str++, i++, my_putchar('%');
        else if (*str == '%') {
            str++;
            if (print_format(ap, &str, &i) == -1)
                return (84);
        } else
            i++, my_putchar(*str);
    }
    va_end(ap);
    return (i);
}

int print_format(va_list ap, char **str, int *i)
{
    char *result;
    flags_t *flags = get_flags(str);

    result = conversion_specifier(ap, str, i, flags);
    if (result == NULL)
        return (-1);
    if (flags->alternate)
        alternate_form(str, &result);
    if (flags->field_width > my_strlen(result))
        field_width(&result, flags);
    my_putstr(result, i);
    return (0);
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

char *conversion_specifier(va_list ap, char **str, int *i, flags_t *flags)
{
    char *modifier;

    if (**str == 'c')
        return my_charstr(va_arg(ap, unsigned int));
    if (**str == 'p')
        return my_putptr(va_arg(ap, void *));
    if (**str == 's')
        return my_strdup(va_arg(ap, char *), flags);
    if (**str == 'S')
        return my_showstr(va_arg(ap, char *), flags);
    modifier = get_length_modifier(str);
    if (**str == 'i' || **str == 'd')
        return get_id(ap, modifier, flags);
    if (is_in_str("bouxX", **str))
        return get_boux(ap, modifier, str, flags);
    if (**str == 'n')
        return print_n(ap, modifier, i);
    return (NULL);
}
