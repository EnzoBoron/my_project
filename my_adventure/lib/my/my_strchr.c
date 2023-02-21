/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** my_strchr
*/

#include "my.h"

char *my_strchr(const char *string, int searchedChar)
{
    int i = 0;
    int a = 0;
    char *end_string = malloc(sizeof(char) * (my_strlen(string) + 1));

    for (; string[i] != searchedChar; i++);
    for (; string[i] != '\0'; i++, a++)
        end_string[a] = string[i];

    return end_string;
}
