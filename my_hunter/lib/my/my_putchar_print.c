/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** number
*/

#include <unistd.h>

int my_putchar_print(int a)
{
    write(1, &a, 1);
    return 0;
}
