/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** placement_direction
*/

#include "my_hunter.h"

life *move_sprite(sfSprite *ball, life *l, element *e, spidy_annimation *s)
{
    if (l->x == -200) {
        l->x = e->pos.x;
        l->y = e->pos.y;
    }
    if (l->x == 5000) {
        l->x = e->pos.x;
        l->y = e->pos.y;
    }
    l->x = (l->x != -200 || l->x != 5000) ? l->x - 0.5 : nothing();
    sfSprite_setPosition(ball, (sfVector2f){l->x, l->y});
    sfSprite_setRotation(ball, l->rota_ball += 0.5);
    return l;
}

void placement_text(sfText* text_esay, sfText* text_medium, sfText* text_hard)
{
    int x = 1920 / 2 - 50;
    int y = 1026 / 2 - 50;
    sfText_setPosition(text_esay, (sfVector2f){x - 200, y - 100});
    sfText_setPosition(text_medium, (sfVector2f){x - 150, y});
    sfText_setPosition(text_hard, (sfVector2f){x - 250, y + 100});
}

void is_click(sfVector2i position_mouse, element *e)
{
    if (position_mouse.x >= 715 && position_mouse.x <= 1034) {
        if (position_mouse.y >= 369 && position_mouse.y <= 421){
            (e->event.type == sfEvtMouseButtonPressed) ?
            gameplay(e) : nothing();
        }
    }
}

void print_score(life *l)
{
    sfText *score_text = create_text("Score");
    sfText *score_number;
    sfFont* font;

    font = sfFont_createFromFile("font/Mightyspidey.ttf");
    score_number = sfText_create();
    sfText_setColor(score_number, sfBlack);
    sfText_setString(score_number, "a");
    sfText_setFont(score_number, font);
    sfText_setCharacterSize(score_number, 50);
}

void trow_ball_sprit(element *e, spidy_annimation *s, life *l)
{
    if (l->x == e->pos.x - 1) {
        sfTime d = {500000};
        sfVector2f pos_gob = sfSprite_getPosition(s->globin_one);
        sfSprite_setPosition(s->globin_one, (sfVector2f){30000, pos_gob.y});
        sfRenderWindow_drawSprite(e->win, s->globin_one, NULL);
        sfSprite_setPosition(s->goblin_two, (sfVector2f){1500, pos_gob.y});
        sfRenderWindow_drawSprite(e->win, s->goblin_two, NULL);
        sfRenderWindow_display(e->win);
        sfSleep(d);
        sfSprite_setPosition(s->goblin_two, (sfVector2f){3000, pos_gob.y});
        sfSprite_setPosition(s->globin_one, (sfVector2f){1500, pos_gob.y});
        sfRenderWindow_drawSprite(e->win, s->globin_one, NULL);
        sfRenderWindow_drawSprite(e->win, s->goblin_two, NULL);
        sfRenderWindow_display(e->win);
    }
}
