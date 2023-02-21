/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** number
*/

#include "../../include/my.h"

int my_put_nbr_print(int nb)
{
    int cmp_carac = 0;

    if (nb < 0) {
        my_putchar_print('-');
        nb = nb * (-1);
    }
    if (nb > 9) {
        my_put_nbr_print(nb / 10);
        my_put_nbr_print(nb % 10);
    } else {
        my_putchar_print(nb + 48);
        cmp_carac++;
    }
    return cmp_carac;
}
