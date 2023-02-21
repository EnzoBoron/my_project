/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-enzo.boron
** File description:
** my_str_to_world_array
*/

#include "my.h"

int number_of_word(char *str)
{
    int i = 0;
    int nb_word = 0;

    for (; str[i] != '\0'; i++)
        if (!my_bsq(str[i - 1]) && my_bsq(str[i]))
            nb_word++;
    return nb_word;
}

char *return_one_word(char *str)
{
    int i = 0;
    char *tab = malloc(sizeof(char) * my_strlen(str + 1));

    for (; !my_bsq(str[i]); i++);
    for (int a = 0; a != i; a++) {
        tab[a] = str[i];
        tab[a + 1] = '\0';
    }
    tab = my_strchr(str, i);
    return tab;
}

char **traitement_string(int nb_word, char *str, char **my_str)
{
    int i = 0;
    int y = 0;

    for (; y < nb_word; y++) {
    my_str[y] = malloc(sizeof(char) * (my_strlen(str) + 1));
        for (int v = 0; my_bsq(str[i]); i++, v++) {
            my_str[y][v] = str[i];
            my_str[y][v + 1] = '\0';
        }
    for (; !my_bsq(str[i]); i++);
        my_str[y + 1] = NULL;
    }
    return my_str;
}

char **my_str_to_world_array(char *str)
{
    char **my_str = NULL;
    int nb_word = number_of_word(str);
    int y = 0;
    int size = 0;

    my_str = malloc(sizeof(char *) * (nb_word + 1));
    my_str = traitement_string(nb_word, str, my_str);
    return my_str;
}
