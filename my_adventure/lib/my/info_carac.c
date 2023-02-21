/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-enzo.boron
** File description:
** info_carac
*/

#include "my.h"

void get_around(char **map, int pos_x, int pos_y, around *a)
{
    for (int i = 1; map[i] != NULL; i++) {
        for (int y = 1; map[i][y] != '\0'; y++) {
            a->pos = (i == pos_y && y == pos_x) ? map[i][y] : a->pos;
            a->up = (i == pos_y && y == pos_x) ? map[i - 1][y] : a->up;
            a->down = (i == pos_y && y == pos_x) ? map[i + 1][y] : a->down;
            a->left = (i == pos_y && y == pos_x) ? map[i][y - 1] : a->left;
            a->ri = (i == pos_y && y == pos_x) ? map[i][y + 1] : a->ri;
        }
    }
}

void get_d_arround(char **map, int px, int py, around *a)
{
    for (int i = 2; map[i] != NULL; i++) {
        for (int y = 2; map[i][y] != '\0'; y++) {
            (map[i + 2] != NULL) ?
                a->d_up = (i == py && y == px) ? map[i - 2][y] : a->d_up,
                a->d_down = (i == py && y == px) ? map[i + 2][y] : a->d_down,
                a->d_left = (i == py && y == px) ? map[i][y - 2] : a->d_left,
                a->d_ri = (i == py && y == px) ? map[i][y + 2] : a->d_ri
                : nothing();
        }
    }
}
