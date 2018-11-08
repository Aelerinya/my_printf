/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** Converts a decimal number in the base given as string.
*/

#include <stdlib.h>
#include "header.h"

char *my_nbr_base(unsigned long long nbr, char const *base, flags_t *flags)
{
    int base_length;
    int size = 2;
    char *result;
    unsigned long long power;

    for (base_length = 0; base[base_length] != '\0'; base_length++);
    for (power = base_length; power <= nbr; power *= base_length, size++);
    if (flags->precision != -1 && flags->precision + 1 > size)
        size = flags->precision + 1;
    result = malloc(sizeof(char) * size);
    for (int j = 0; j < size; result[j++] = base[0]);
    result[size - 1] = '\0';
    for (int i = size - 2; i >= 0; i--) {
        result[i] = base[nbr % base_length];
        nbr /= base_length;
    }
    if (result[0] == '0' && result[1] == '\0' && flags->precision == 0)
        result[0] = '\0';
    return (result);
}
