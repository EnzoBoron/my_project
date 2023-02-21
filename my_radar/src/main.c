/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myradar-enzo.boron
** File description:
** main
*/

#include "../include/my_radar.h"

int output_verification(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Air traffic simulation panel\n\n");
        my_putstr("USAGE\n");
        my_putstr("    ./my_radar [OPTIONS] path_to_script\n");
        my_putstr("    path_to_script     The path to the script file.\n\n");
        my_putstr("OPTIONS\n");
        my_putstr("-h          print the usage and quit.\n\n");
        my_putstr("USER INTERACTIONS\n");
        my_putstr("‘L’ key         enable/disable hitboxes and areas.\n");
        my_putstr("‘S’ key         enable/disable sprites.\n");
        return 0;
    }
    return 1;
}

int main(int ac, char **av)
{
    int x = output_verification(ac, av);
    if (x != 1)
        return x;
    get_element *g = malloc(sizeof(get_element));
    airplane *a = NULL;
    the_tower *t = NULL;
    window *w = malloc(sizeof(window));
    file_info(av[1], g);
    char **file = my_str_to_world_array(g->contenu);
    a = coordonnee_plane(file, a);
    t = coordonnee_tower(file, t);
    w->win = create_window(1920, 1080);
    sfWindow_setFramerateLimit(w->win, 60);
    loop_game_my_radar(w, a, t);
    free(a);
    free(g);
    return 0;
}
