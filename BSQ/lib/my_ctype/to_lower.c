/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** to_lower
*/

#include "my_ctype.h"

int to_lower(char a)
{
    if (a >= 'A' && a <= 'Z')
        return a += 20;
    return 0;
}
