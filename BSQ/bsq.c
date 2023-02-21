/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-enzo.boron
** File description:
** bsq
*/

#include "bsq.h"

int min(int x_un, int y_un, int xy_un)
{
    int i = '0';

    for (i = '0'; i <= '9'; i++) {
        if (xy_un == i) {
            return xy_un;
        } if (y_un == i) {
            return y_un;
        } if (x_un == i) {
            return x_un;
        }
    }
    return '0';
}

void display_tab(char **tab)
{
    for (int i = 1; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    my_free(tab);
}

void on_square_x(char **tab)
{
    for (int x = 0; tab[1][x] != '\0'; x++) {
        if (tab[1][x] == '.') {
            tab[1][x] = 'x';
            break;
        }
    }
    for (int x = 0; tab[1][x] != '\0'; x++) {
        my_putchar(tab[1][x]);
    }
    my_putchar('\n');
}

void start(char *file)
{
    char buf[1], **tab = NULL;
    int coordonees[3] = { 0 }, fd = 0, nb_caractere = how_many_letter(file);
    char *str = malloc(sizeof(char) * (nb_caractere + 1));
    fd = open(file, O_RDONLY);
    (fd < 0) ? my_error("error opening file", 84) : nothing();
    str = assignation_valeur(fd, buf, str);
    tab = my_str_to_world_array_bsq(str);
    if (tab[2] == NULL) on_square_x(tab);
    else {
        tab = transform_in_number(tab);
        find_the_bigger_square(tab, coordonees);
        tab = transform_in_original(tab);
        tab = put_caractere_x(tab, coordonees);
        display_tab(tab);
        free(str);
    }
    close(fd);
}

int main(int argv, char **argc)
{
    if (argv < 2 || argv > 2)
        my_error("wrong number of arguments", 84);
    if (argc[1][0] == '.')
        my_error("Wrong file", 84);
    start(argc[1]);
    return 0;
}
