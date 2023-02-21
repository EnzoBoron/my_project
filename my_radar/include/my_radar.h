/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-enzo.boron
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    #include "my.h"

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Types.h>

    #include <math.h>
    #include <stdio.h>

    typedef struct airplane airplane;
    struct airplane {
        int a, x, y, x2, y2, v, o;
        int vx, vy;
        sfSprite *plane;
        airplane *next;
    };

    typedef struct the_tower the_tower;
    struct the_tower {
        int t, x, y;
        int r;
        sfCircleShape *circle;
        sfSprite *tower;
        the_tower *next;
    };

    typedef struct window window;
    struct window {
        sfRenderWindow *win;
        sfEvent event;
    };

    int destroy_end_game(airplane *a, the_tower *t, sfSprite *background);
    void loop_game_my_radar(window *w, airplane *a, the_tower *t);
    sfSprite *display_sprite(char *name, const sfIntRect *area);
    airplane *remove_collision_plane(airplane *a);
    airplane *remove_finish_plane(airplane *a, the_tower *t);
    the_tower *coordonnee_tower(char **file, the_tower *t);
    void display_sprite_aireplane(airplane *a, window *w);
    airplane *coordonnee_plane(char **file, airplane *a);
    void display_liken_list(airplane *a, the_tower *t);
    void display_sprite_tower(the_tower *d, window *w);
    airplane *where_is_the_location(airplane *a);
    sfRenderWindow *create_window(int x, int y);
    the_tower *add_node_tower(the_tower *n);
    airplane *add_node_plane(airplane *n);

#endif /* !MY_RADAR_H_ */
