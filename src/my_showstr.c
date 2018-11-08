/*
** EPITECH PROJECT, 2018
** my_showstr
** File description:
** Prints a string and display hex codes of non-printable characters
*/

#include "header.h"
#include <stdlib.h>

static void fill_string(char const *str, char *result)
{
    int k = 0;
    char *octal = "01234567";

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] < 32 || str[j] >= 127) {
            result[k] = 92;
            result[k + 1] = octal[str[j] / 64];
            result[k + 2] = octal[str[j] / 8 % 8];
            result[k + 3] = octal[str[j] % 8];
            k += 4;
        } else
            result[k] = str[j], k++;
    }
}

char *my_showstr(char const *str, flags_t *flags)
{
    char *result;
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++, size++)
        if (str[i] < 32 || str[i] >= 127)
            size += 3;
    result = malloc(sizeof(char) * (size + 1));
    result[size] = '\0';
    fill_string(str, result);
    if (flags->precision != -1 && flags->precision < size)
        result[flags->precision] = '\0';
    return (result);
}
