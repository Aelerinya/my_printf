/*
** EPITECH PROJECT, 2018
** flags.c
** File description:
** My_printf flag management
*/

#include "header.h"
#include <stdlib.h>

static int is_in_str(char *str, char c)
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
    int correct = 0;

    if (**str == '#' && flag->alternate == 0)
        (*str)++, flag->alternate = 1, correct = 1;
    if (**str == '0' && flag->zero_padding == 0)
        (*str)++, flag->zero_padding = 1, correct = 1;
    if (**str == '-' && flag->left_adjusting == 0)
        (*str)++, flag->left_adjusting = 1, correct = 1;
    if (**str == ' ' && flag->space == 0)
        (*str)++, flag->space = 1, correct = 1;
    if (**str == '+' && flag->force_sign == 0)
        (*str)++, flag->force_sign = 1, correct = 1;
    if (**str == '.' && flag->precision == -1) {
        if ((*str)[1] == '-' && is_in_str("0123456789", (*str)[2]))
            my_strtol(*str + 2, str), correct = 1;
        else
            flag->precision = my_strtol(*str + 1, str), correct = 1;
    } else if (is_in_str("123456789", **str) && flag->field_width == 0)
        flag->field_width = my_strtol(*str, str), correct = 1;
    return correct;
}

flags_t *get_flags(char **str)
{
    flags_t *flag = init_flag();

    while (is_in_str("#0- +*.123456789", **str)) {
        if (update_flag(str, flag) == 0)
            return NULL;
    }
    return flag;
}
