/*
** EPITECH PROJECT, 2018
** my_nbr_to_str
** File description:
** Convert an int into a string
*/

#include <stdlib.h>
#include "header.h"

char *my_nbr_to_str(long long int nb, flags_t *flags)
{
    char *str;
    int put_sign = (nb < 0 || flags->space || flags->force_sign) ? 1 : 0;
    int size = 2 + put_sign;
    int negative = (nb < 0) ? 1 : 0;
    
    nb = (nb < 0) ? -nb : nb;
    for (long long int power = 10; power <= nb; power *= 10, size++);
    str = malloc(sizeof(char) * size);
    str[size - 1] = '\0';
    if (flags->space)
        str[0] = ' ';
    if (flags->force_sign)
        str[0] = '+';
    if (negative)
        str[0] = '-';
    for (int i = size - 2; i >= put_sign; i--) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}
