/*
** EPITECH PROJECT, 2022
** my_str_isupper.c
** File description:
** str_isupper
*/

#include "../../include/my.h"

int my_str_isupper(char const *str)
{
    int i = 0;
    int a = 0;
    int b = 0;

    for (; str[i] != '\0'; i++){
        if (str[i] >= 97 && str[i] <= 122)
            a++;
        else
            b++;
    }
    if (b == my_strlen(str))
        return 1;
    return 0;
}
