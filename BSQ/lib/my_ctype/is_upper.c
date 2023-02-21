/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_upper
*/

#include "my_ctype.h"

int is_upper(char a)
{
    if (a >= 'A' && a <= 'Z')
        return 1;
    return 0;
}
