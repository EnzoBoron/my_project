/*
** EPITECH PROJECT, 2022
** my_double_print.c
** File description:
** double
*/

#include "../../include/my.h"

int my_double_print(double a)
{
    int left = a;
    double right = (((double)a - (double)left) * (int)1000000);
    int i;

    if (right < ((double)a - (double)left) * (int)1000000)
        right++;
    my_put_nbr(left);
    my_putchar('.');
    for (i = 0; right < 100000; i++) {
        my_put_nbr(0);
        right *= 10;
    }
    for (; i > 0; i--)
        right /= 10;
    my_put_nbr(right);
    return 0;
}
