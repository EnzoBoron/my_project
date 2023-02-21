/*
** EPITECH PROJECT, 2022
** my_put_positive_print.c
** File description:
** positive number
*/

#include "../../include/my.h"

int my_positive_nbr_print(int a)
{
    if (a > 0) {
        my_putchar('+');
        my_put_nbr(a);
    } else {
        my_put_nbr(a);
    }
    return 0;
}
