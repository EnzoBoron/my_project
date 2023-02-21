/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-enzo.boron
** File description:
** collision_plane
*/

#include "../include/my_radar.h"

int destroy_end_game(airplane *a, the_tower *t, sfSprite *background)
{
    sfSprite_destroy(background);
    for (; a->next != NULL; a = a->next)
        free(a);
    free(a);
    for (; t->next != NULL; t = t->next)
        free(t);
    free(t);
    return 0;
}

airplane *remove_finish_plane(airplane *a, the_tower *t)
{
    airplane *tmp = a, *before = a;
    if (a == NULL)
        return;
    if (a->x == a->x2 && a->y == a->y2) {
        before = a;
        a = a->next;
        before = NULL;
        return;
    }
    for (;tmp->next != NULL; tmp = tmp->next)
        if (tmp->x == tmp->next->x2 && tmp->next->y == tmp->next->y2) {
            before = tmp;
            before->next = (tmp->next->next != NULL) ? tmp->next->next :
            before->next;
            before->next = (tmp->next->next == NULL) ? NULL : before->next;
            tmp = NULL;
            return a;
        }
    return a;
}

airplane *remove_collision_plane(airplane *a)
{
    airplane *tmp_a = a;
    airplane *tmp_ab = a;
    airplane *before = NULL;

    for (; tmp_a->next != NULL; tmp_a = tmp_a->next) {
        for (; tmp_ab->next != NULL; tmp_ab = tmp_ab->next) {
            if (tmp_a->x < tmp_ab->x + 10 &&
                tmp_a->x + 10 > tmp_ab->x &&
                tmp_a->y < tmp_ab->y + 10 &&
                10 + tmp_a->y > tmp_ab->y) {
                before = tmp_ab;
                tmp_ab = before->next;
                before = NULL;
            }
        }
    }
    return a;
}
