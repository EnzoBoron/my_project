/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #include "include/my.h"
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Types.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>

    int nothing(void);

    typedef struct spidy_annimation {
        sfSprite *globin_one;
        sfSprite *goblin_two;
    } spidy_annimation;

    typedef struct element {
        sfRenderWindow *win;
        sfEvent event;
        sfText *text_esay;
        sfText *text_medium;
        sfText *text_hard;
        sfMusic *music_acceuil;
        sfSprite *bouffon;
        sfVector2f pos;
        sfVector2i pos_mouse;
        sfSprite *ball_bouffon;
    }element;

    typedef struct life {
        int valeur;
        int score;
        char *scores;
        sfText *text_score;
        double x;
        double y;
        sfSprite *spidy_one;
        sfSprite *spidy_two;
        sfSprite *spidy_tree;
        float rota_ball;
    }life;

    sfRenderWindow *create_window(int x, int y);
    sfSprite *display_sprite(char *name, const sfIntRect *area);
    sfSprite *display_spite_custom(char *, const sfVector2f, sfVector2f);
    void draw_text(sfRenderWindow *window_option, sfText* text_esay,
    sfText* text_medium, sfText* text_hard);
    void display_option(element *e);
    sfText *create_text(char *name);
    void gameplay(element *e);
    life *move_sprite(sfSprite *, life *, element *e, spidy_annimation *s);
    void placement_text(sfText* text_esay, sfText* text_medium, sfText*);
    void is_click(sfVector2i position_mouse, element *e);
    void print_score(life *l);
    void trow_ball_sprit(element *e, spidy_annimation *s, life *l);
    void destroy_gameplay(spidy_annimation *s, element *e, life *l);
    void destroy_all(element *e);
    void init_sprit(spidy_annimation *s, life *l);
    char * transform_in_char(int nb);
    int second_verification_file(int a, sfImage *o);
    void is_clic_medium(sfVector2i position_mouse, element *e);
    void gameplay_medium(element *e);
    void gameplay_hard(element *e);
#endif /* !MY_HUNTER_H_ */
