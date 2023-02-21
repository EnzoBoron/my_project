/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** one by one
*/

#include <unistd.h>

int my_putstr_print(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    return 0;
}
