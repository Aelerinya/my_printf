/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** Converts a decimal number in the base given as string.
*/

#include "header.h"

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int digit;
    int base_length;

    for (base_length = 0; base[base_length] != '\0'; base_length++);
    digit = nbr % base_length;
    nbr /= base_length;
    if (nbr > 0)
        my_putnbr_base(nbr, base);
    my_putchar(base[digit]);    
    return (0);
}
