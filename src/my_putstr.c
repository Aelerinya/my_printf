/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Print string on screen using my_putchar
*/

void my_putchar(char c);

int my_putstr(char const *str, int *j)
{
    for (int i = 0; str[i] != '\0'; i++) {
        (*j)++, my_putchar(str[i]);
    }
    return (0);
}
