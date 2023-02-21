/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** option
*/

#include "my_hunter.h"

void display_option(element *e)
{
    sfSprite *background_option = display_sprite("asset/background.jpg", NULL);
    sfSprite *spidy_option = display_sprite("asset/spidy.png", NULL);
    e->text_esay = create_text("EASY");
    e->text_medium = create_text("MEDIUM");
    e->text_hard = create_text("HARD");
    while (sfRenderWindow_isOpen(e->win)) {
        while (sfRenderWindow_pollEvent(e->win, &e->event))
            (e->event.type == sfEvtClosed) ? destroy_all(e),
            sfRenderWindow_close(e->win) : nothing();
        loop_option(e, spidy_option, background_option);
    }
}

void loop_option(element *e, sfSprite *spidy_option, sfSprite *background)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(e->win);
    is_click(pos_mouse, e);
    is_clic_medium(pos_mouse, e);
    is_clic_hard(pos_mouse, e);
    placement_text(e->text_esay, e->text_medium, e->text_hard);
    sfRenderWindow_clear(e->win, sfBlack);
    sfRenderWindow_drawSprite(e->win, background, NULL);
    sfRenderWindow_drawSprite(e->win, spidy_option, NULL);
    draw_text(e->win, e->text_esay, e->text_medium, e->text_hard);
    sfRenderWindow_display(e->win);
}
