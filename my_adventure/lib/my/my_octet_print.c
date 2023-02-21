/*
** EPITECH PROJECT, 2022
** my_octal_print.c
** File description:
** convertiseur octal
*/

#include "../../include/my.h"

int diviser(int nb, int a)
{
    int i = 0;

    for (i = 0; nb >= a; i++)
    nb = nb - a;
    return i;
}

void display_octal(int save[100], int i)
{
    for (; i >= 0; i--) {
    if (save[i] > 7) {
    my_putchar(save[i] + 16);
    }
    if (save[i] < 8) {
    my_put_nbr(save[i]);
    }
    }
}

int my_octet_print(int x)
{
    int quotient;
    int save[100];
    int i = 1;

    if (x > 7) {
    save[0] = x % 8;
    quotient = diviser(x, 8);
    while (quotient > 7) {
    save[i] = quotient % 8;
    quotient = diviser(quotient, 8);
    i++;
    }
    save[i] = quotient;
    display_octal(save, i);
    return i;
    }
    if (x < 8 && x >= 0) {
    my_put_nbr(x);
    }
    return i;
}
