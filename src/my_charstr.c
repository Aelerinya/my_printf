/*
** EPITECH PROJECT, 2018
** my_charstr
** File description:
** Convert a char to a one character string
*/

#include <stdlib.h>

char *my_charstr(char c)
{
    char *result = malloc(sizeof(char) * 2);

    result[0] = c;
    result[1] = '\0';
    return result;
}
