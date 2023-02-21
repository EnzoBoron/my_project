/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_alpha
*/

#include "my_ctype.h"

int is_alpha(char a)
{
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return 1;
    return 0;
}
