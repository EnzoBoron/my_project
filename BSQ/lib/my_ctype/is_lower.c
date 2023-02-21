/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_lower
*/

#include "my_ctype.h"

int is_lower(char a)
{
    if (a >= 'a' && a <= 'z')
        return 1;
    return 0;
}
