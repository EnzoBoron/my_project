/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-enzo.boron
** File description:
** deplacement_direction
*/

#include "../include/my_radar.h"

airplane *where_is_the_location(airplane *a)
{
    airplane *tmp = a;
    tmp->vx = 1; tmp->vy = 1;
    if (tmp->x2 - tmp->x > 0)
        tmp->vx = 1;
    if (tmp->x2 - tmp->x < 0)
        tmp->vx = -1;
    if (tmp->y2 - tmp->y > 0)
        tmp->vy = 1;
    if (tmp->y2 - tmp->y < 0)
        tmp->vy = -1;
    if (tmp->y2 - tmp->y == 0)
        tmp->vy = 0;
    if (tmp->x2 - tmp->x == 0)
        tmp->vx = 0;
    tmp->vx = tmp->vx * tmp->v;
    tmp->vy = tmp->vy * tmp->v;
    return tmp;
}
