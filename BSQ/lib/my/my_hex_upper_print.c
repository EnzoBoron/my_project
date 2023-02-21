/*
** EPITECH PROJECT, 2022
** B-CPE-101-LIL-1-1-myprintf-enzo.boron
** File description:
** my_hex_upper_print
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <stdlib.h>

int puissance(long int x, long int nb, int base)
{
    while ((x * base) <= nb)
        x = x * base;
    return x;
}

int display_hex(long int nb, long int plus)
{
    if (nb > 9)
        my_putchar(nb + plus);
    if (nb < 10)
        my_put_nbr(nb);
    return 0;
}

int big_hex(long int d, long int r, int x, int p)
{
    int i = 1;
    int save[1000];

    d = puissance(16, x, 16);
    r = x % d;
    save[0] = diviser(x, d);
    while (r > 15) {
        x = r;
        d = puissance(16, x, 16);
        r = x % d;
        save[i] = diviser(x, d);
        i++;
    }
    save[i] = r;
    for (int c = 0; c <= i; c++)
        display_hex(save[c], p);
    if (x < 16)
        display_hex(x, p);
    return i;
}

int my_hex_upper_print(long int x)
{
    int diviseur;
    int reste;
    int i;

    if (x > 15)
        i = big_hex(diviseur, reste, x, 55);
    else
        display_hex(x, 55);
        return 0;
}
