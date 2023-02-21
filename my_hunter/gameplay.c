/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** gameplay
*/

#include "my_hunter.h"

void shoot_ball(life *l,  element *e, sfSprite *ball)
{
    e->pos_mouse = sfMouse_getPosition(e->win);
    sfFloatRect size_ball = sfSprite_getGlobalBounds(ball);
    if (e->pos_mouse.y >= size_ball.top &&
    e->pos_mouse.y <= (size_ball.top + size_ball.height))
        if (e->pos_mouse.x >= size_ball.left &&
        e->pos_mouse.x <= (size_ball.left + size_ball.width))
            l->x = (e->event.type == sfEvtMouseButtonPressed) ?
            l->score++, 5000 : l->x;
}

void display_life(life *l,  element *e, spidy_annimation *s)
{
    if (l->x == -200)
        l->valeur -= 1;
    (!l->valeur) ? destroy_gameplay(s, e, l), display_option(e) : nothing();
    if (l->valeur == 3)
        sfRenderWindow_drawSprite(e->win, l->spidy_one, NULL);
    if (l->valeur == 2)
        sfRenderWindow_drawSprite(e->win, l->spidy_two, NULL);
    if (l->valeur == 1)
        sfRenderWindow_drawSprite(e->win, l->spidy_tree, NULL);
    return;
}

void annimation_bouffon(element *e, life *l, spidy_annimation *s)
{
    e->pos = sfSprite_getPosition(s->globin_one);
    if (e->pos.y == 200 && (l->x == 5000 || l->x == -200)) {
        sfSprite_setPosition(s->globin_one, (sfVector2f){1500, 300});
        e->pos.y = 300;
        return;
    }
    if (e->pos.y == 300 && (l->x == 5000 || l->x == -200)) {
        sfSprite_setPosition(s->globin_one, (sfVector2f){1500, 500});
        e->pos.y = 500;
        return;
    }
    if (e->pos.y == 500 && (l->x == 5000 || l->x == -200)) {
        sfSprite_setPosition(s->globin_one, (sfVector2f){1500, 200});
        e->pos.y = 200;
        return;
    }
}

void loop_gameplay(life *l, element *e, sfSprite *back, spidy_annimation *s)
{
    sfFloatRect size_ball = sfSprite_getGlobalBounds(e->ball_bouffon);
    sfRenderWindow_drawSprite(e->win, back, NULL);
    shoot_ball(l, e, e->ball_bouffon);
    annimation_bouffon(e, l, s);
    trow_ball_sprit(e, s, l);
    move_sprite(e->ball_bouffon, l, e, s);
    sfRenderWindow_drawSprite(e->win, e->ball_bouffon, NULL);
    if (l->x != e->pos.x - 1)
        sfRenderWindow_drawSprite(e->win, s->globin_one, NULL);
    display_life(l, e, s);
    l->scores = transform_in_char(l->score);
    sfText_destroy(l->text_score);
    l->text_score = create_text(l->scores);
    sfText_setPosition(l->text_score, (sfVector2f){100, 900});
    sfRenderWindow_drawText(e->win, l->text_score, NULL);
    sfRenderWindow_display(e->win);
}

void gameplay(element *e)
{
    life *l = malloc(sizeof(life));
    spidy_annimation *s = malloc(sizeof(spidy_annimation));
    l->x = 1500, l->y = 300;
    l->valeur = 3;
    l->score = 0;
    l->scores = transform_in_char(l->score);
    l->text_score = create_text(l->scores);
    init_sprit(s, l);
    sfSprite *background = display_sprite("asset/background.jpg", NULL);
    e->ball_bouffon = display_spite_custom("asset/bombe_boufon_0.png",
    (sfVector2f){2000, 2000}, (sfVector2f){0.3, 0.3});
    sfSprite_setOrigin(e->ball_bouffon, (sfVector2f){100, 100});
    l->rota_ball = sfSprite_getRotation(e->ball_bouffon);
    sfFloatRect my_pos = sfSprite_getGlobalBounds(e->ball_bouffon);
    while (sfRenderWindow_isOpen(e->win)) {
        while (sfRenderWindow_pollEvent(e->win, &e->event))
            (e->event.type == sfEvtClosed) ? sfRenderWindow_close(e->win)
            : nothing();
        loop_gameplay(l, e, background, s);
    }}
