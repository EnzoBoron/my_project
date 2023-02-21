/*
** ENZO, THOMAS, MARIE 2022
** my_adventure
** File description:
** display
*/

#include "my_adventure.h"

void switch_menu(poubelle *p, get_element *e)
{
    int highlight = 2;
    switch (p->touche) {
        case 'z':
            highlight--;
            if (highlight == -1)
                highlight = 2;
            break;
        case 's':
            highlight++;
            if (highlight == 3)
            highlight = 2;
            break;
        default:
            highlight = 2;
            break;
    }
}

void menu(poubelle *p, get_element *e)
{
    getmaxyx(stdscr, p->term_y,p->term_x);
    noecho();
    clear();
    p->menuwin = newwin(6, p->term_x-6,p->term_y -6,5), p->touche = 1;
    box(p->menuwin,0,0);
    refresh();
    wrefresh(p->menuwin);
    start_color();
    refresh();
    char choices[2][33] = { "Play","Option"};
    do {
        for (int i = 0; i < 2; i++) {
            mvwprintw(p->menuwin,i+1,2,choices[i]);
        }
        switch_menu(p, e);
        p->touche = wgetch(p->menuwin);
    } while (p->touche != 10);
    clear();
}

void wait(poubelle *p, get_element *e, char letter)
{
    while (p->touche != letter) {
        window_too_little(p);
        noecho();
        p->touche = getch();
    }
    clear();
}
