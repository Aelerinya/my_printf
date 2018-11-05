/*
** EPITECH PROJECT, 2018
** my_putptr
** File description:
** Print a pointer in hexadecimal
*/

#include "header.h"

static void rec_put_ptr(long int ptr)
{
    int digit;
    char *hexa = "0123456789abcdef";

    digit = ptr % 16;
    ptr = ptr / 16;
    if (ptr > 0)
        rec_put_ptr(ptr);
    my_putchar(hexa[digit]);
}

void my_putptr(void *ptr)
{
    my_putstr("0x");
    rec_put_ptr((long int)ptr);
}
