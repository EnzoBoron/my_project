/*
** ENZO, THOMAS, 2022
** my_adventure
** File description:
** create
*/

#include "my_adventure.h"

void create_box(poubelle *p)
{
    for (int i = 0; p->maps[i] != NULL; i++) {
        move(((p->term_y / 2) - p->nb_caractere) + i,
        (p->term_x - p->nb_caractere) / 2);
        color_door();
        printw(p->maps[i]);
        printw("\n");
    }
    wrefresh(stdscr);
    return;
}

void create_box_menu (int x, int y)
{
    int tmp_x = 0, tmp_y = 0;
    for (tmp_x = 0; tmp_x <= y; tmp_x++) {
        printw("_");
    }
    printw("\n");
    for (tmp_y = 2; tmp_y <= x; tmp_y++) {
        printw("|");
        for (tmp_x = 2; tmp_x <= y; tmp_x++) {
            printw(" ");
        }
        printw("|");
        printw("\n");
    }
    printw("|");
    for (tmp_x = 1; tmp_x <= (y - 1); tmp_x++) {
        printw("_");
    }
    printw("|");
}

void create_dialogue(poubelle *p, char *message, int x, int y)
{
    for (int i = 0; p->maps[i] != NULL; i++) {
            move(y, x);
            printw(message);
            printw("\n");
    }
    wrefresh(stdscr);
    return;
}
