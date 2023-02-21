/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_punct
*/

#include "my_ctype.h"

int is_punct(char a)
{
    if (a >= 33 && a <= 47)
        return 1;
    if (a >= 58 && a <= 64)
        return 1;
    if (a >= 92 && a <= 96)
        return 1;
    if (a >= 123 && a <= 126)
        return 1;
    return 0;
}
