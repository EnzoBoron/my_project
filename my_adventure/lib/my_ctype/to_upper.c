/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** to_upper
*/

#include "my_ctype.h"

int to_upper(char a)
{
    if (a >= 'a' && a <= 'z')
        return a -= 20;
    return 0;
}
