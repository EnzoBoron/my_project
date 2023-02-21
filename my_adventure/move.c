/*
** ENZO, THOMAS, 2022
** my_adventure
** File description:
** move
*/

#include "my_adventure.h"

void my_door(poubelle *p, get_element *e)
{
    if (p->touche == 'z') {
        p->index -= 1;
        my_tp(p, e);
    }
    if (p->touche == 's') {
        p->index += 1;
        my_tp(p, e);
    }
    if (p->touche == 'q') {
        p->index -= 1;
        my_tp(p, e);
    }
    if (p->touche == 'd') {
        p->index += 1;
        my_tp(p, e);
    }
}

void move_caractere(poubelle *p, get_element *e)
{
    around *a = malloc(sizeof(around));
    get_around(p->maps, p->x, p->y, a);
    if ((p->touche == 'z' && a->up != '*') ||
    (p->touche == 'z' && a->up == ' '))
        p->y -= 1;
    if ((p->touche == 's' && a->down != '*') ||
    (p->touche == 's' && a->down == ' '))
        p->y += 1;
    if ((p->touche == 'q' && a->left != '*') ||
    (p->touche == 'q' && a->left == ' '))
        p->x -= 1;
    if ((p->touche == 'd' && a->ri != '*') ||
    (p->touche == 'd' && a->ri == ' ')) {
        p->x += 1;
    }
    if ((a->up == '0' || a->down == '0') ||
    a->left == '0' || a->ri == '0') {
        my_door(p, e);
    }
}

void remove_carac(poubelle *p)
{
    for (int i = 0; p->maps[i] != NULL; i++) {
        for (int j = 0; p->maps[i][j] != '\0'; j++) {
            p->maps[i][j] = (p->y == i && p->x == j) ? ' ' : p->maps[i][j];
        }
    }
}

void enemy(poubelle *p)
{
    around *a = malloc(sizeof(around));
    get_around(p->maps, p->x, p->y, a);
    if (a->pos == '+' || a->pos == '#')
        p->life -= 1;
    if (a->pos == '~')
        p->life -= 2;
}

void dead_save(poubelle *p, get_element *e)
{
    if ((p->life == 0 || p->life < 0) && p->save_x != 0) {
        p->index = p->save_index;
        p->x = p->save_x;
        p->y = p->save_y;
        p->life = 5;
        my_tp(p, e);
    } else if (p->life == 0 && p->save_x == 0) {
        exit(0);
    }
}
