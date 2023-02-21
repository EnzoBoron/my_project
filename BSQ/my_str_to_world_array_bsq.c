/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-enzo.boron
** File description:
** my_str_to_world_array_bsq
*/

#include "bsq.h"

void my_free(char **my_str)
{
    for (int i = 0; my_str[i] != 0; i++)
        free(my_str[i]);
    free(my_str);
}

int my_bsq_type(char a)
{
    if (a == '.' || a == 'o' || a == 'x' || (a >= '0' && a <= '9'))
        return 1;
    return 0;
}

int number_of_word_bsq(char *str)
{
    int i = 0;
    int nb_word = 0;

    for (; str[i] != '\0'; i++)
        if (!my_bsq_type(str[i + 1]) && my_bsq_type(str[i]))
            nb_word++;
    return nb_word;
}

char **traitement_string_bsq(int nb_word, char *str, char **my_str)
{
    int i = 0;
    int y = 0;

    for (y = 0; y < nb_word; y++) {
    my_str[y] = malloc(sizeof(char) * (my_strlen(str) + 1));
        for (int v = 0; my_bsq_type(str[i]); i++, v++) {
            my_str[y][v] = str[i];
            my_str[y][v + 1] = '\0';
        }
    for (; !my_bsq_type(str[i]); i++);
    my_str[y + 1] = NULL;
    }
    return my_str;
}

char **my_str_to_world_array_bsq(char *str)
{
    char **my_str = NULL;
    int nb_word = number_of_word_bsq(str);

    my_str = malloc(sizeof(char *) * (nb_word + 1));
    my_str = traitement_string_bsq(nb_word, str, my_str);
    return my_str;
}
