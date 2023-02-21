/*
** EPITECH PROJECT, 2022
** my_strlowcase.c
** File description:
** strlowcase
*/

#include <unistd.h>
int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 91 && str[i] > 64) {
            str[i] = str[i] + 32;
        }
    }
    return (str);
}
