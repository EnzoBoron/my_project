/*
** EPITECH PROJECT, 2022
** B-MUL-100-LIL-1-1-myhunter-enzo.boron
** File description:
** destoy
*/

#include "my_hunter.h"

void destroy_gameplay(spidy_annimation *s, element *e, life *l)
{
    sfSprite_destroy(s->globin_one);
    sfSprite_destroy(s->goblin_two);
    sfSprite_destroy(e->bouffon);
    sfSprite_destroy(l->spidy_one);
    sfSprite_destroy(l->spidy_two);
    sfSprite_destroy(l->spidy_tree);
    sfSprite_destroy(e->ball_bouffon);
}

void destroy_all(element *e)
{
    // sfText_destroy(e->text_esay);
    // sfText_destroy(e->text_medium);
    // sfText_destroy(e->text_hard);
    sfMusic_destroy(e->music_acceuil);
    // sfRenderWindow_destroy(e->win);
}

int my_strlen_int(int nb)
{
    if (nb - 9 < 0)
        return 1;
    if (nb - 99 < 0)
        return 2;
    if (nb - 999 < 0)
        return 3;
    if (nb - 9999 < 0)
        return 4;
    return 84;
}

char * transform_in_char(int nb)
{
    char *str = malloc(sizeof(char) * (my_strlen_int(nb) + 1));
    if (nb > 9) {
        str[0] = nb / 10 + '0';
        str[1] = nb % 10 + '0';
        str[2] = '\0';
        return str;
    } else if (nb < 10) {
        str[0] = nb + '0';
        str[1] = '\0';
        return str;
    }
}

int second_verification_file(int a, sfImage *o)
{
    o = sfImage_createFromFile("asset/spidy.png");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/sprite_one.png");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/sprite_two.png");
    if (!o) return 84;
    o = sfImage_createFromFile("asset/sprite_sheet.png");
    if (!o) return 84;
    return a;
}
