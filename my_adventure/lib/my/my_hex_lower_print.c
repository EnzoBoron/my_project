/*
** EPITECH PROJECT, 2022
** mini_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

int my_hex_lower_print(long int x)
{
    int diviseur;
    int reste;
    int i;

    if (x > 15) {
        i = big_hex(diviseur, reste, x, 87);
    }
    if (x < 16)
        display_hex(x, 87);
    return 0;
}
