/*
** EPITECH PROJECT, 2018
** my_nbr_to_str
** File description:
** Convert an int into a string
*/

#include <stdlib.h>
#include "header.h"

static char *prepare_result(flags_t *flags, int size, int negative)
{
    char *str;

    str = malloc(sizeof(char) * size);
    for (int j = 0; j < size; str[j++] = '0');
    str[size - 1] = '\0';
    if (flags->space)
        str[0] = ' ';
    if (flags->force_sign)
        str[0] = '+';
    if (negative)
        str[0] = '-';
    return (str);
}

char *my_nbr_to_str(long long int nb, flags_t *flags)
{
    char *str;
    int put_sign = (nb < 0 || flags->space || flags->force_sign) ? 1 : 0;
    int size = 2 + put_sign;
    int negative = (nb < 0) ? 1 : 0;

    nb = (nb < 0) ? -nb : nb;
    for (long long int power = 10; power <= nb; power *= 10, size++);
    if (flags->precision != -1 && flags->precision + 1 > size)
        size = flags->precision + 1;
    str = prepare_result(flags, size, negative);
    for (int i = size - 2; i >= put_sign; i--) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    if (str[0] == '0' && str[1] == '\0' && flags->precision == 0)
        str[0] = '\0';
    return (str);
}
