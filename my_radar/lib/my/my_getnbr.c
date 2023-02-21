/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr
*/

#include <stdio.h>

int my_getnbr(char *a)
{
    int res = 0;

    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            res *= 10;
            res += a[i] - '0';
        }
    }
    for (int i = 0; a[i] != '\0'; i++){
        if (a[i] == '-')
            return res * -1;
    }
    return res;
}
