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
    char *result;
    char *conversion;
    int size;

    conversion = my_nbr_base((unsigned long long int)ptr, "0123456789abcdef");
    for (size = 0; conversion[size] != '\0'; size++);
    result = malloc(sizeof(char) * (size + 3));
    my_strcpy(result, "0x");
    my_strcpy(result + 2, conversion);
    free(conversion);
    return result;
}
