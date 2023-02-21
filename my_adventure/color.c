/*
** ENZO, THOMAS, MARIE 2022
** my_adventure
** File description:
** color
*/

#include "my_adventure.h"

void color_door(void)
{
    attron(COLOR_PAIR(1));
    init_pair(1, COLOR_YELLOW, 0);
    attroff(COLOR_PAIR(0));
}
