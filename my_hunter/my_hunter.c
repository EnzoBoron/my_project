/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** my_hunter
*/

#include "my_hunter.h"

int verification_file(void)
{
    sfImage *o = NULL;
    int a = 0;
    o = sfImage_createFromFile("asset/background.jpg");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/backgroung_acceuil.jpg");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/bombe_boufon_0.png");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/spider_life_1.png");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/spider_life_2.png");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/spider_life_3.png");
    second_verification_file(a, o);
    sfImage_destroy(o);
    return a;
}

void help(void)
{
    my_putstr("My_hunter est un jeux inspiré de Duck Hunt\n");
    my_putstr("Clique sur les bombes du bouffon vert pour les detruires\n");
    my_putstr("Il existe trois niveaux avec un nombre limiter de vie\n");
}

void boucle_hunter(element *e, sfSprite *background_acceuil)
{
    sfTime t = {3};
    sfRenderWindow_drawSprite(e->win, background_acceuil, NULL);
    sfRenderWindow_display(e->win);
    sfSleep(t);
    display_option(e);
}

void my_hunter(void)
{
    element *e = malloc(sizeof(element));
    e->music_acceuil = sfMusic_createFromFile("music/music_acceuil.ogg");
    sfEvent event;
    e->event = event;
    sfMusic_play(e->music_acceuil);
    sfRenderWindow *window_acceuil = create_window(1920, 1080);
    e->win = window_acceuil;
    sfSprite *background_acceuil =
    display_sprite("asset/backgroung_acceuil.jpg", NULL);
    while (sfRenderWindow_isOpen(window_acceuil)) {
        while (sfRenderWindow_pollEvent(window_acceuil, &event)) {
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window_acceuil)
            : nothing();
        }
        boucle_hunter(e, background_acceuil);
    }
    sfSprite_destroy(background_acceuil);
}

int main(int argc, char **argv)
{
    switch (argc) {
        case 2:
            if (argv[1][0] == '-' && argv[1][1] == 'h')
                help();
            else
                return 84;
            break;
        case 1:
            if (verification_file() > 0) {
                write(2, "Missing file\n", 13);
                return 84;
            }
            my_hunter();
            break;
        default:
            return 84;
    }
    return 0;
}
