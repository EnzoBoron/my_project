/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** direction
*/

#include "my_hunter.h"

void is_clic_medium(sfVector2i position_mouse, element *e)
{
    if (position_mouse.x >= 772 && position_mouse.x <= 1250) {
        if (position_mouse.y >= 489 && position_mouse.y <= 530){
            (e->event.type == sfEvtMouseButtonPressed) ?
            gameplay_medium(e) : nothing();
        }
    }
}

void is_clic_hard(sfVector2i position_mouse, element *e)
{
    if (position_mouse.x >= 672 && position_mouse.x <= 1000) {
        if (position_mouse.y >= 573 && position_mouse.y <= 615){
            (e->event.type == sfEvtMouseButtonPressed) ?
            gameplay_hard(e) : nothing();
        }
    }
}
