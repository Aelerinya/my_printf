/*
** EPITECH PROJECT, 2018
** my_putptr
** File description:
** Print a pointer in hexadecimal
*/

#include <stdlib.h>
#include "header.h"

char *my_putptr(void *ptr)
{
    unsigned long long nbr = (unsigned long long)ptr;
    char *hexa = "0123456789abcdef";
    char *result;
    int size = 4;
    unsigned long long power;

    for (power = 16; power <= nbr; power *= 16, size++);
    result = malloc(sizeof(char) * size);
    my_strcpy(result, "0x");
    result[size - 1] = '\0';
    for (int i = size - 2; i >= 2; i--) {
        result[i] = hexa[nbr % 16];
        nbr /= 16;
    }
    return (result);
}
