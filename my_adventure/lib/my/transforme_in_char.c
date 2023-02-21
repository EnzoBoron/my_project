/*
** EPITECH PROJECT, 2022
** my_adventure
** File description:
** transforme_in_char
*/

#include "my.h"

int my_strlen_int(int nb)
{
    if (nb - 9 < 0)
        return 1;
    if (nb - 99 < 0)
        return 2;
    if (nb - 999 < 0)
        return 3;
    if (nb - 9999 < 0)
        return 4;
    return 84;
}

char * transform_in_char(int nb)
{
    char *str = malloc(sizeof(char) * (my_strlen_int(nb) + 1));
    if (nb > 9 && nb <= 99) {
        str[0] = nb / 10 + '0';
        str[1] = nb % 10 + '0';
        str[2] = '\0';
        return str;
    } else if (nb < 10) {
        str[0] = nb + '0';
        str[1] = '\0';
        return str;
    } else if (nb > 99 && nb < 999) {
        str[0] = nb / 10 + '0';
        str[1] = nb % 10 + '0';
        str[2] = '\0';
        return str;
    }
    return str;
}
