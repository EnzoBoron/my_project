/*
** EPITECH PROJECT, 2022
** ls
** File description:
** transform_in_simple_array
*/

#include "../../include/my.h"
#include <stdlib.h>

char *transform_in_simple_array(char **option)
{
    int i;
    int y;
    char *my_option = 0;

    for (y = 0, i = 1; option[i] != 0; i++, y++)
        my_option = malloc(sizeof(char) * (my_strlen(option[i]) + y));
    if (my_option == 0)
        my_putstr("ERROR MALLOC");
    for (y = 0, i = 1; option[i] != 0; i++, y++) {
            my_option[y + 1] = ' ';
        for (int s = 0; option[i][s] != '\0'; s++, y++)
            my_option[y] = option[i][s];
    }
    my_option[y + 1] = '\0';
}
