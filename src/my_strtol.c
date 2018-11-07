/*
** EPITECH PROJECT, 2018
** my_strtol
** File description:
** Implementation of the strtol function
*/

long int my_strtol(const char *nptr, char **endptr)
{
    long int number = 0;
    int pos;

    for (pos = 0; nptr[pos] >= '0' && nptr[pos] <= '9'; pos++) {
        number *= 10;
        number += nptr[pos] - 48;
    }
    *endptr = (char *)nptr + pos;
    return number;
}
