/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_alnum
*/

#include "my_ctype.h"

int is_alnum(char a)
{
    if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z'))
        return 1;
    if (a >= 'A' && a <= 'Z')
        return 1;
    return 0;
}
