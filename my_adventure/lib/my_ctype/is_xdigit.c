/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_xdigit
*/

#include "my_ctype.h"

int is_xdigit(char a)
{
    if ((a >= 'a' && a <= 'f') || (a >= 'A' && a <= 'F'))
        return 1;
    if (a >= '0' && a <= '9')
        return 1;
    return 0;
}
