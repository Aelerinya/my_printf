/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** My_printf flag management
*/

#include "header.h"
#include <stdlib.h>

int is_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

static flags_t *init_flag(void)
{
    flags_t *flag;

    flag = malloc(sizeof(flags_t));
    flag->alternate = 0;
    flag->zero_padding = 0;
    flag->left_adjusting = 0;
    flag->space = 0;
    flag->force_sign = 0;
    flag->field_width = 0;
    flag->precision = -1;
    return (flag);
}

static int update_flag(char **str, flags_t *flag)
{
    switch (**str) {
    case '#':
        flag->alternate = 1;
        break;
    case '0':
        flag->zero_padding = 1;
        break;
    case '-':
        flag->left_adjusting = 1;
        break;
    case ' ':
        flag->space = 1;
        break;
    case '+':
        flag->force_sign = 1;
        break;
    default :
        return (0);
    }
    return (1);
}

flags_t *get_flags(char **str)
{
    flags_t *flag = init_flag();

    while (update_flag(str, flag))
        (*str)++;
    if (is_in_str("123456789", **str))
        flag->field_width = my_strtol(*str, str);
    if (**str == '.') {
        if ((*str)[1] == '-')
            my_strtol(*str + 2, str);
        else
            flag->precision = my_strtol(*str + 1, str);
    }
    return flag;
}
