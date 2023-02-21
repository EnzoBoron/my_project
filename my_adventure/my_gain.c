/*
** EPITECH PROJECT, 2022
** my_adventure
** File description:
** my_gain
*/

#include "my_adventure.h"

void gain_money(poubelle *p, get_element *e)
{
    around *a = malloc(sizeof(around));
    get_around(p->maps, p->x, p->y, a);
    if (a->pos == '$') {
        p->money += 1;
        how_many_letter_line(e, p->maps, p->y - 1);
        remove_text((p->x + p->y), '$', e, p->path_salle[p->index]);
        file_info( p->path_salle[p->index], e);
        p->maps = my_str_to_world_array(e->contenu);
    }
}

void gain_regen(poubelle *p, get_element *e)
{
    around *a = malloc(sizeof(around));
    get_around(p->maps, p->x, p->y, a);
    if (a->pos == '|' && (a->d_ri == '/' || a->left == '/')) {
        p->life += 2;
        p->index = p->save_index;
        how_many_letter_line(e, p->maps, p->y - 1);
        remove_text(p->x, '|', e, p->path_salle[p->index]);
        file_info( p->path_salle[p->index], e);
        p->maps = my_str_to_world_array(e->contenu);
        p->save_y = p->y;
        p->save_x = p->x;
    }
}

void gain_chest(poubelle *p, get_element *e)
{
    around *a = malloc(sizeof(around));
    get_around(p->maps, p->x, p->y, a);
    if (a->pos == '.') {
        srand(time(NULL));
        p->money += rand() % 3;
        p->life += rand() % 2;
        how_many_letter_line(e, p->maps, p->y - 1);
        remove_text(p->x, '.', e, p->path_salle[p->index]);
        file_info( p->path_salle[p->index], e);
        p->maps = my_str_to_world_array(e->contenu);
    }
}

void gain(poubelle *p, get_element *e)
{
    gain_money(p, e);
    gain_regen(p, e);
    gain_chest(p, e);
}
