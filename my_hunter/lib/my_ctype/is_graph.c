/*
** EPITECH PROJECT, 2022
** my_ctype
** File description:
** is_graph
*/

#include "my_ctype.h"

int is_graph(char a)
{
    if (a >= 33 && a <= 126)
        return 1;
    return 0;
}
