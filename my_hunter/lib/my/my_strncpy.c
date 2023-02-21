/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** copy
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int a;

    if (n < my_strlen(src)) {
        for (a = 0; a < n && src[a] != '\0'; a++)
            dest[a] = src[a];
        for (; a < n; a++)
            dest[a] = '\0';
    }
    if (n > my_strlen(src)) {
        for (a = 0; src[a] != '\0'; a++)
            dest[a] = src[a];
        dest[a] = '\0';
    }
    return dest;
}
