/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** init_sprite
*/

#include "my_hunter.h"

void init_sprit(spidy_annimation *s, life *l)
{
    s->globin_one = display_spite_custom("asset/sprite_one.png" ,
    (sfVector2f){l->x, l->y}, (sfVector2f){1, 1});
    s->goblin_two = display_spite_custom("asset/sprite_two.png" ,
    (sfVector2f){l->x, l->y}, (sfVector2f){1, 1});
    l->spidy_one = display_spite_custom("asset/spider_life_3.png",
    (sfVector2f){10, 10}, (sfVector2f){0.3, 0.3});
    l->spidy_two = display_spite_custom("asset/spider_life_2.png",
    (sfVector2f){10, 10}, (sfVector2f){0.3, 0.3});
    l->spidy_tree = display_spite_custom("asset/spider_life_1.png",
    (sfVector2f){10, 10}, (sfVector2f){0.3, 0.3});
}
