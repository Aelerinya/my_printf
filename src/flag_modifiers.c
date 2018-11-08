/*
** EPITECH PROJECT, 2018
** flag_modifiers
** File description:
** Function that modifies the output of my_printf based on active flags
*/

#include "header.h"
#include <stdlib.h>

void alternate_form(char **str, char **result)
{
    char *new_result;

    if (**str == 'x' || **str == 'X') {
        new_result = malloc(sizeof(char) * (my_strlen(*result) + 2));
        my_strcpy(new_result, (**str == 'x') ? "0x" : "0X");
        my_strcpy(new_result + 2, *result);
        free(*result);
    } else if (**str == 'o' && **result != '0') {
        new_result = malloc(sizeof(char) * (my_strlen(*result) + 1));
        my_strcpy(new_result, "0");
        my_strcpy(new_result + 1, *result);
        free(*result);
    } else
        new_result = *result;
    *result = new_result;
}
