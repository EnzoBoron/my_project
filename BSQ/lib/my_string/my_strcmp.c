/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** my_strcmp
*/

#include "my_string.h"

int comparaison_lettre(char lettre1, char lettre2)
{
    if (lettre1 > lettre2)
        return 1;
    return -1;
}

int my_strcmp(const char* str1, const char* str2)
{
    int i = 0;
    int a = 0;

    if (my_strlen(str1) > my_strlen(str2))
        return 1;
    if (my_strlen(str1) < my_strlen(str2))
        return -1;
    for (; str1[i] != '\0' && str2[a] != '\0'; i++, a++)
        if (str1[i] != str2[a])
            return comparaison_lettre(str1[i], str2[a]);
    return 0;
}
