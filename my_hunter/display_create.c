/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** display_create
*/

#include "my_hunter.h"

sfRenderWindow *create_window(int x, int y)
{
    sfVideoMode mode = {x, y, 32};
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, "My_hunter", sfResize | sfClose, NULL);
    return window;
}

sfSprite *display_sprite(char *name, const sfIntRect *area)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(name, area);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

sfSprite *display_spite_custom(char *name, const sfVector2f area, sfVector2f si)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(name, NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, area);
    sfSprite_setScale(sprite, si);
    return sprite;
}

void draw_text(sfRenderWindow *window_option, sfText* text_esay,
sfText* text_medium, sfText* text_hard)
{
    sfRenderWindow_drawText(window_option, text_esay, NULL);
    sfRenderWindow_drawText(window_option, text_medium, NULL);
    sfRenderWindow_drawText(window_option, text_hard, NULL);
}

sfText *create_text(char *name)
{
    sfText* text_esay;
    sfFont* font;

    font = sfFont_createFromFile("font/Mightyspidey.ttf");
    text_esay = sfText_create();
    sfText_setColor(text_esay, sfBlack);
    sfText_setString(text_esay, name);
    sfText_setFont(text_esay, font);
    sfText_setCharacterSize(text_esay, 50);
    return text_esay;
}
