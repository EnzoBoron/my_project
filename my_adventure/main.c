/*
** ENZO THOMAS, 2022
** my_adventure
** File description:
** main
*/

#include "my_adventure.h"

void window_too_little(poubelle *p)
{
    if (p->term_x < 35 || p->term_y < 35 ||
        (p->term_x < 35 && p->term_y < 35)) {
            clear();
            move(p->term_y / 2, p->term_x / 2);
            printw("Window is too small");
    }
}

void my_adventure_loop(poubelle *p, get_element *e)
{
    while (p->touche != 27) {
        dead_save(p, e);
        getmaxyx(stdscr, p->term_y, p->term_x);
        window_too_little(p);
        keypad(stdscr, 1);
        mvaddch(p->y, p->x, p->user);
        mvprintw(1, 0, transform_in_char(p->money));
        for (int i = 0; i < p->life; i++) {
            mvprintw(0, 0 + i, "|");
        }
        p->touche = getch();
        move_caractere(p, e);
        enemy(p);
        gain(p, e);
        clear();
        create_box(p);
    }
}

void my_free(poubelle *p, get_element *e)
{
    for (int i = 0; p->maps[i] != 0; i++)
        free(p->maps[i]);
    free(p->maps);
    for (int i = 0; p->path_salle[i] != 0; i++)
        free(p->path_salle[i]);
    free(p->path_salle);
    free(p);
    free(e->contenu);
    free(e);
}

int main(void)
{
    poubelle *p = malloc(sizeof(poubelle));
    p->x = 10, p->y = 5, p->user = 'l', p->index = 0, p->life = 5, p->money = 0;
    get_element *e = malloc(sizeof(get_element));;
    init_aray(p, e);
    reset_my_map(p, e);
    file_info(p->path_salle[p->index], e);
    p->maps = my_str_to_world_array(e->contenu);
    p->nb_caractere = e->number_letter;
    initscr();
    start_color();
    refresh();
    curs_set(0);
    getmaxyx(stdscr, p->term_y, p->term_x);
    menu(p, e);
    //clear();
    create_box(p);
    create_dialogue(p, "Ail ques que je fais ici ?", 2, 5);
    wait(p, e, 'a');
    my_adventure_loop(p, e);
    endwin();
    my_free(p, e);
    return 0;
}
