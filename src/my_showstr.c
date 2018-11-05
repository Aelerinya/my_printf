/*
** EPITECH PROJECT, 2018
** my_showstr
** File description:
** Prints a string and display hex codes of non-printable characters
*/

#include "header.h"

int my_showstr(char const *str, int *j)
{
    char *octal = "01234567";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar(92);
            my_putchar(octal[str[i] / 64]);
            my_putchar(octal[str[i] / 8 % 8]);
            my_putchar(octal[str[i] % 8]);
            (*j) += 4;
        } else {
            (*j)++, my_putchar(str[i]);
        }
    }
    return (0);
}
