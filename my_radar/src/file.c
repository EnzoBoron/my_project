/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-enzo.boron
** File description:
** file
*/

#include "../include/my_radar.h"

airplane *coordonnee_plane(char **file, airplane *a)
{
    for (int i = 0; file[i] != NULL; i += 1) {
        if (file[i][0] == 'A') {
            a = add_node_plane(a);
            a->a = a->a + 1;
            a->x = my_getnbr(file[i + 1]);
            a->y = my_getnbr(file[i + 2]);
            a->x2 = my_getnbr(file[i + 3]);
            a->y2 = my_getnbr(file[i + 4]);
            a->v = my_getnbr(file[i + 5]);
            a->o = my_getnbr(file[i + 6]);
            a = where_is_the_location(a);
        }
    }
    return a;
}

the_tower *coordonnee_tower(char **file, the_tower *t)
{
    for (int i = 0; file[i] != NULL; i += 1) {
        if (file[i][0] == 'T') {
            t = add_node_tower(t);
            t->t = t->t + 1;
            t->x = my_getnbr(file[i + 1]);
            t->y = my_getnbr(file[i + 2]);
            t->r = my_getnbr(file[i + 3]);
        }
    }
    return t;
}
