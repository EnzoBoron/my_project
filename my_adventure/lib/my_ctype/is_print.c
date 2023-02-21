/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_print
*/

#include "my_ctype.h"

int is_print(char a)
{
    if (a >= 0 && a <= 122)
        return 1;
    return 0;
}
