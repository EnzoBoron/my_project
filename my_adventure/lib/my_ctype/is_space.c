/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_space
*/

#include "my_ctype.h"

int is_space(char a)
{
    if (a == 32)
        return 1;
    if (a == '\t')
        return 1;
    if (a == '\n')
        return 1;
    if (a == '\v')
        return 1;
    if (a == 'f')
        return 1;
    if (a == '\r')
        return 1;
    return 0;
}
