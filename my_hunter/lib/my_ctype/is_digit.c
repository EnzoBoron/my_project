/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_digit
*/

#include "my_ctype.h"

int is_digit(char a)
{
    if (a >= '0' && a <= '9')
        return 1;
    return 0;
}
