/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** my_strcpy
*/

#include "my_string.h"

char* my_strcpy(char* destination, const char* source)
{
    int i = 0;

    for (; source[i] != '\0'; i++)
        destination[i] = source[i];

    return destination;
}
