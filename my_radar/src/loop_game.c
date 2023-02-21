/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-enzo.boron
** File description:
** loop_game
*/

#include "../include/my_radar.h"

void display_sprite_aireplane(airplane *a, window *w)
{
    airplane *tmp = a;
    for (; tmp != NULL; tmp = tmp->next) {

        sfRectangleShape *rect = sfRectangleShape_create();
        sfVector2f size; size.x = 20; size.y = 20;
        sfRectangleShape_setSize(rect, size);
        sfRectangleShape_setFillColor(rect, sfTransparent);
        sfRectangleShape_setOutlineColor(rect, sfBlack);
        sfRectangleShape_setOutlineThickness(rect, 2);
        tmp->x = tmp->x + tmp->vx;
        tmp->y = tmp->y + tmp->vy;
        sfVector2f pos; pos.x = tmp->x; pos.y = tmp->y;
        sfRectangleShape_setPosition(rect, pos);
        sfSprite_setPosition(a->plane, pos);
        sfRenderWindow_drawSprite(w->win, a->plane, NULL);
        sfRenderWindow_drawRectangleShape(w->win, rect, NULL);
        a = remove_collision_plane(a);
    }
}

void display_sprite_tower(the_tower *d, window *w)
{
    the_tower *tmp = d;
    for (; tmp != NULL; tmp = tmp->next) {
        sfVector2f pos; pos.x = tmp->x; pos.y = tmp->y;
        sfVector2f center; center.x = tmp->r - 10; center.y = tmp->r - 10;
        sfCircleShape_setRadius(tmp->circle, tmp->r);
        sfCircleShape_setOrigin(tmp->circle, center);
        sfCircleShape_setPosition(tmp->circle, pos);
        sfCircleShape_setFillColor(tmp->circle, sfTransparent);
        sfShape_setOutlineColor(tmp->circle, sfBlack);
        sfShape_setOutlineThickness(tmp->circle, 2);
        sfSprite_setPosition(tmp->tower, pos);
        sfRenderWindow_drawSprite(w->win, tmp->tower, NULL);
        sfRenderWindow_drawCircleShape(w->win, tmp->circle, NULL);
    }
}

void loop_game_my_radar(window *w, airplane *a, the_tower *t)
{
    sfSprite *background = display_sprite("asset/world.jpg", NULL);
    sfClock *clock = sfClock_create();
    sfClock_restart(clock);


    while (sfRenderWindow_isOpen(w->win)) {
        while (sfRenderWindow_pollEvent(w->win, &w->event)) {
            (w->event.type == sfEvtClosed) ? sfRenderWindow_close(w->win)
            : nothing();
        }
        sfRenderWindow_clear(w->win, sfBlack);
        sfRenderWindow_drawSprite(w->win, background, NULL);
        display_sprite_aireplane(a, w);
        a = remove_finish_plane(a, t);
        printf("%.1d\n", clock);
        display_sprite_tower(t, w);
        sfRenderWindow_display(w->win);
    }
}
