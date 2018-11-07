/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** Converts a decimal number in the base given as string.
*/

#include <stdlib.h>
#include "header.h"

char *my_nbr_base(unsigned long long int nbr, char const *base)
{
    int base_length;
    int size = 2;
    char *result;
    unsigned long long power;

    for (base_length = 0; base[base_length] != '\0'; base_length++);
    for (power = base_length; power <= nbr; power *= base_length, size++);
    result = malloc(sizeof(char) * size);
    result[size - 1] = '\0';
    for (int i = size - 2; i >= 0; i--) {
        result[i] = base[nbr % base_length];
        nbr /= base_length;
    }
    return (result);
}
