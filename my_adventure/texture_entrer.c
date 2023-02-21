/*
** ENZO THOMAS, 2022
** my_adventure
** File description:
** texture_entrer
*/

#include "my_adventure.h"

void display_grotte_principal(poubelle *p)
{
    for (int i = 0; i <= p->term_y; i++) {
        for (int j = 0; j <= p->term_x; j++) {
            printw("Y");
        }
    }
}

void rect(poubelle *p)
{
    for (int i = 0; i <= 20; i++) {
        for (int y = 0; y <= p->term_x / 2; y++) {
            printw(" ");
        }
    }
}
