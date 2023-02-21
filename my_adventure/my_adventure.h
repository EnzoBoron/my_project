/*
** ENZO THOMMAS, 2022
** my_adventure
** File description:
** my_adventure
*/

#ifndef MY_ADVENTURE_H_
    #define MY_ADVENTURE_H_
    #include "lib/my/my.h"
    #include <ncurses.h>
    #include <curses.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    #include <stdio.h>

    typedef struct poubelle {
        int term_x;
        int term_y;
        int touche;
        int x;
        int y;
        char user;
        char **maps;
        int nb_caractere;
        char **path_salle;
        int index;
        int life;
        int money;
        char *save;
        int save_x;
        int save_y;
        int save_index;
        WINDOW *menuwin;
        WINDOW *win;
        char **choices;
    } poubelle;

    void how_many_letter_line(get_element *, char**, int);
    char *remove_text(int, char, get_element *, char*);
    void create_dialogue(poubelle *, char *,int ,int);
    void my_adventure_loop(poubelle *, get_element *);
    void reset_map(get_element *, char *, char *);
    void reset_my_map(poubelle *, get_element *);
    void move_caractere(poubelle *, get_element *);
    void get_around(char **, int, int, around *);
    void wait(poubelle *, get_element *, char);
    void switch_menu(poubelle *, get_element *);
    void init_aray (poubelle *, get_element *);
    void display_grotte_principal(poubelle *);
    void dead_save(poubelle *, get_element *);
    void my_free(poubelle *, get_element *);
    void my_tp(poubelle *, get_element *);
    void file_info(char *, get_element *);
    char **my_str_to_world_array(char *);
    void menu(poubelle *, get_element *);
    void gain(poubelle *, get_element *);
    void window_too_little(poubelle *);
    void create_box_menu (int, int);
    char * transform_in_char(int);
    void create_box(poubelle *);
    void enemy(poubelle *);
    void rect(poubelle *);
    void color_door(void);

#endif /* !MY_ADVENTURE_H_ */
