/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** strcat
*/

#include "my_string.h"

char *my_strcat(char *dest ,char const *src)
{
    int nb = (my_strlen(dest) + my_strlen(src));
    int i = 0;
    int a = 0;
    char *fin = malloc(sizeof(char) * (nb + 1));
    for (; src[i] != '\0'; i++)
        fin[i] = src[i];
    for (; dest[a] != '\0'; i++, a++)
        fin[i] = dest[a];
    fin[i] = '\0';
    return fin;
}
