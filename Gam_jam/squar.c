/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** the main brach
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct gam {
    sfRenderWindow* window;
    sfMusic* music;
    sfEvent event;
    int score;
    sfSprite *back;
} game_t;

typedef struct squa {
    sfSprite *sprite;
    sfTexture *texture;
    float seconds;
    float pre_sec;
    int indice;
    sfCircleShape *circle;
    float radus;
    int first;
    int pos_x, pos_y;
    struct squa *next;
} squar_t;

sfClock *sec;

int my_bulle_redirection(game_t *game, squar_t *squar);

int nothing(void)
{
    return 0;
}

void create_window(int x, int y, game_t *game)
{
    sfVideoMode mode = {x, y, 32};
    game->window = sfRenderWindow_create(mode, "My_circle", sfResize | sfClose, NULL);
    if (!game->window)
        exit(3);
}

squar_t *add_node_head(squar_t *squar, int loop)
{
    sfTexture *texture = sfTexture_createFromFile("asset/bombe.png", NULL);
    for (int i = 0; i < loop; i++) {
        squar_t *tmp = malloc(sizeof(squar_t));
        tmp->circle = sfCircleShape_create();
        sfCircleShape_setTexture(tmp->circle, texture, 0);
        tmp->indice = 0;
        tmp->first = 0;
        tmp->next = squar;
        squar = tmp;
    }
    return squar;
}

squar_t *add_node_tail(squar_t *list, int loop)
{
    if (list == NULL) {
        list = add_node_head(list, loop);
        return list;
    }
    for (int i = 0; i < loop; i++) {
        sfTexture *texture = sfTexture_createFromFile("asset/bombe.png", NULL);
        squar_t *node = malloc(sizeof(squar_t));
        squar_t *tmp = list;
        node->indice = 0;
        node->first = 0;
        node->circle = sfCircleShape_create();
        sfCircleShape_setTexture(node->circle, texture, 0);
        node->next = NULL;
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
    return list;
}

void display_liken_list(squar_t *sqart, game_t *game)
{
    squar_t *tmp = sqart;
    int valider = 0;
    for (int i = 0; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawCircleShape(game->window, tmp->circle, NULL);
    }
}

squar_t *less_rad(squar_t *squar)
{
    for (squar_t *tmp= squar; tmp != NULL; tmp = tmp->next) {
        tmp->radus -=  0.003;
        if (tmp->radus > 20 && tmp->radus < 100 && tmp->indice == 0)
            sfCircleShape_setRadius(tmp->circle, tmp->radus);
        else {
            sfCircleShape_setPosition(tmp->circle, (sfVector2f){-100, -100});
            tmp->indice = 1;
        }
    }
    return squar;
}

squar_t *done_number(squar_t *squar)
{
    squar_t *tmp = squar;
    srand( time(NULL));
    for (; tmp != NULL; tmp = tmp->next) {
        while (tmp->first == 1)
            tmp = tmp->next;
        while (tmp->radus < 10)
            tmp->radus = rand() % 100;
        tmp->first = 1;
        sfCircleShape_setRadius(tmp->circle, tmp->radus);
        tmp->pos_x = rand() % 1800;
        tmp->pos_y = rand() % 1000;
        sfCircleShape_setPosition(tmp->circle, (sfVector2f){tmp->pos_x, tmp->pos_y});
        sfCircleShape_setOrigin(tmp->circle, (sfVector2f){tmp->radus, tmp->radus});
    }
    return squar;
}

squar_t *click_squar(squar_t *squar, game_t *game)
{
    int save = game->score + 1;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    for (squar_t *tmp = squar; tmp != NULL; tmp = tmp->next)
        if (game->event.type == sfEvtMouseButtonPressed && (pos.x - tmp->pos_x) * (pos.x - tmp->pos_x) + (pos.y - tmp->pos_y) * (pos.y - tmp->pos_y) <= tmp->radus * tmp->radus) {
            sfCircleShape_setPosition(tmp->circle, (sfVector2f){-200, -200});
            tmp->indice = 2;
            game->score = game->score + 1;
        }
    if (game->score > save)
        game->score = 1;
    return squar;
}

squar_t *create_circle(squar_t *squar, int loop)
{
    squar_t *tmp = add_node_tail(squar, loop);
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->radus = 20;
    sfCircleShape_setRadius(tmp->circle, 0);
    sfCircleShape_setFillColor(tmp->circle, sfWhite);
    sfCircleShape_setPosition(tmp->circle, (sfVector2f){0, 0});
    return squar;
}

squar_t *get_time(squar_t *squar, game_t *game)
{
    sfTime elapsedTime = sfClock_getElapsedTime(sec);
    squar->seconds = elapsedTime.microseconds / 1000000.0f;
    sfText *round, *llvl, *t_score;
    sfFont *font, *lvl, *f_score;

    char buffer[32], buffer_score[32];
    sprintf(buffer, "%.2f", squar->seconds);
    sprintf(buffer_score, "%d", game->score);
    lvl = sfFont_createFromFile("font/Roboto/Roboto-Light.ttf");
    f_score = sfFont_createFromFile("font/Roboto/Roboto-Light.ttf");
    llvl = sfText_create();
    t_score = sfText_create();
    sfText_setString(llvl, buffer);
    sfText_setFont(llvl, lvl);
    sfText_setString(t_score, buffer_score);
    sfText_setFont(t_score, f_score);
    sfVector2f p = {1850 - 30, 10};
    sfVector2f q = {40, 10};
    sfText_setPosition(t_score, q);
    sfText_setPosition(llvl, p);
    sfRenderWindow_drawText(game->window, llvl, NULL);
    sfRenderWindow_drawText(game->window, t_score, NULL);
    sfText_setFillColor(llvl, sfWhite);
    sfText_setFillColor(t_score, sfWhite);

    if ((squar->pre_sec + 1.00000) < squar->seconds && squar->seconds < 15.0) {
        srand( time(NULL));
        int t = rand() % 4;
        squar = create_circle(squar, 3);
        squar = done_number(squar);
        squar->pre_sec = (squar->seconds + 0.10000);
    }

    if (squar->seconds >= 15 && squar->seconds <= 20) {
        for (squar_t *tmp = squar; tmp != NULL; tmp = tmp->next) {
            sfCircleShape_setPosition(tmp->circle, (sfVector2f){-500, -500});
        }
        font = sfFont_createFromFile("font/Roboto/Roboto-Light.ttf");
        round = sfText_create();
        sfText_setString(round, "NEXT ROUND");
        sfText_setFont(round, font);
        sfVector2f v = {1920 / 2 - 30, 1080 / 2 - 30};
        sfText_setPosition(round, v);
        sfRenderWindow_drawText(game->window, round, NULL);
        sfText_setFillColor(round, sfWhite);
    }
    if (squar->seconds >= 20 && squar->seconds < 30 && (squar->pre_sec + 1.00000) < squar->seconds) {
        squar = create_circle(squar, 5);
        squar = done_number(squar);
        squar->pre_sec = (squar->seconds + 0.10000);
    }
    if (squar->seconds >= 30) {
        sfFont *fon = sfFont_createFromFile("font/Roboto/Roboto-Light.ttf");
        sfText *roun = sfText_create();
        sfText_setString(roun, "SCORE :");
        sfText_setFont(roun, fon);
        sfVector2f d = {1920 / 2 - 30, 1080 / 2 - 30};
        sfText_setPosition(roun, d);
        sfRenderWindow_drawText(game->window, roun, NULL);
        sfText_setFillColor(roun, sfWhite);

        sfRenderWindow_clear(game->window, sfBlack);
        sfFont *fo = sfFont_createFromFile("font/Roboto/Roboto-Light.ttf");
        sfSprite_setPosition(game->back, (sfVector2f){450, 0});
        sfRenderWindow_drawSprite(game->window, game->back, NULL);
        sfText *rou = sfText_create();
        sfText_setString(rou, "RETRY");
        sfText_setFont(rou, fo);
        sfVector2f v = {1920 / 2, 1080 / 2 + 50};
        sfText_setPosition(rou, v);
        sfRenderWindow_drawText(game->window, rou, NULL);
        sfText_setFillColor(rou, sfWhite);
        sfRenderWindow_display(game->window);
        
        while (sfMouse_isButtonPressed(sfMouseLeft) != 1) {
            nothing();
        }
        my_bulle_redirection(game, squar);
    }
    return squar;
}

sfSprite *display_sprite(char *name, const sfIntRect *area)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(name, area);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    return sprite;
}

int loop_game(game_t *game, squar_t *squar)
{
    squar->pre_sec = 0;
    squar = create_circle(squar, 5);
    squar = done_number(squar);
    char text[20];
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            if (game->event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
        }
        sfRenderWindow_clear(game->window, sfBlack);
        sfSprite_setPosition(game->back, (sfVector2f){450, 0});
        sfRenderWindow_drawSprite(game->window, game->back, NULL);
        display_liken_list(squar, game);
        squar = less_rad(squar);
        squar = click_squar(squar, game);
        squar = get_time(squar, game);
        sfRenderWindow_display(game->window);
    }
}

int accueil_space(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    game->back = display_sprite("./asset/back.png", NULL);
    sfSprite_setPosition(game->back, (sfVector2f){450, 0});
    sfRenderWindow_drawSprite(game->window, game->back, NULL);
    sfFont *font = sfFont_createFromFile("font/Roboto/Roboto-Light.ttf");
    sfText *round = sfText_create();
    sfText_setString(round, "CLICK FOR PLAY");
    sfText_setFont(round, font);
    sfVector2f v = {1920 / 2 - 30, 1080 / 2 - 30};
    sfText_setPosition(round, v);
    sfRenderWindow_drawText(game->window, round, NULL);
    sfText_setFillColor(round, sfWhite);
    sfRenderWindow_display(game->window);

    sfEvent event;
    while (1) {
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            if (event.type == sfEvtMouseButtonPressed)
                break;
        }
        if (event.type == sfEvtMouseButtonPressed)
                break;
    }
}

int my_bulle_redirection(game_t *game, squar_t *squar)
{
    //for (; game != NULL; game = game ->next);
    for (; squar != NULL; squar = squar->next);
    //sfMusic_play(game->music);
    //sec = sfClock_create();
    game->score = 0;
    free(game->back);
    squar->seconds = 0;
    accueil_space(game);
    loop_game(game, squar);
}

int my_bulle(void)
{
    game_t *game = malloc(sizeof(game_t));
    squar_t *squar = malloc(sizeof(squar_t));
    create_window(1920, 1080, game);
    game->music = sfMusic_createFromFile("music/music_ambiamce.ogg");
    sfMusic_play(game->music);
    accueil_space(game);
    sec = sfClock_create();
    game->score = 0;
    squar->circle = sfCircleShape_create();
    squar->next = NULL;
    loop_game(game, squar);
}

int main(void)
{
    my_bulle();
    return 0;
}
