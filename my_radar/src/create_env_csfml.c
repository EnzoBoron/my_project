/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-enzo.boron
** File description:
** create_env_csfml
*/

#include "../include/my_radar.h"

sfSprite *display_sprite(char *name, const sfIntRect *area)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(name, area);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

airplane *add_node_plane(airplane *n)
{
    airplane *node = malloc(sizeof(airplane));
    node->plane = display_sprite("asset/plane.png", NULL);
    node->next = n;
    return node;
}

the_tower *add_node_tower(the_tower *n)
{
    the_tower *tmp = malloc(sizeof(the_tower));
    tmp->tower = display_sprite("asset/tower.png", NULL);
    tmp->circle = sfCircleShape_create();
    tmp ->next = n;
    return tmp;
}

sfRenderWindow *create_window(int x, int y)
{
    sfVideoMode mode = {x, y, 32};
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, "My_radar", sfResize | sfClose, NULL);
    return window;
}
