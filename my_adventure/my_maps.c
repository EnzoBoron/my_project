/*
** ENZO, THOMAS, MARIE 2022
** my_adventure
** File description:
** my_maps
*/

#include "my_adventure.h"

void init_aray (poubelle *p, get_element *e)
{
    p->path_salle = malloc(sizeof(char)*30);
    p->path_salle[0] = malloc(sizeof(char*) * 30);
    p->path_salle[1] = malloc(sizeof(char*) * 30);
    p->path_salle[2] = malloc(sizeof(char*) * 30);
    p->path_salle[3] = malloc(sizeof(char*) * 30);
    p->path_salle[0] = "asset/acceuil.txt";
    p->path_salle[1] = "asset/sale_1.txt";
    p->path_salle[2] = "asset/salle_2.txt";
    p->path_salle[3] = "asset/salle_3.txt";
}

void reset_my_map(poubelle *p, get_element *e)
{
    reset_map(e, "asset/original/original_acceuil.txt", "asset/acceuil.txt");
    reset_map(e, "asset/original/original_sale_1.txt", "asset/sale_1.txt");
    reset_map(e, "asset/original/original_salle_2.txt", "asset/salle_2.txt");
    reset_map(e, "asset/original/original_salle_2b.txt", "asset/salle_2b.txt");
    reset_map(e, "asset/original/original_salle_3.txt", "asset/salle_3.txt");
}

void find_d(poubelle *p, get_element *e)
{
    for (int i = 0; p->maps[i] != NULL; i++) {
        for (int y = 0; p->maps[i][y] != '\0'; y++) {
            p->x = (p->maps[i][y] == 'D') ? y + 1 : p->x ;
            p->y = (p->maps[i][y] == 'D') ? i : p->y;
        }
    }
}

void my_tp(poubelle *p, get_element *e)
{
    clear();
    p->maps[0] = NULL;
    get_element *f = malloc(sizeof(get_element));
    file_info(p->path_salle[p->index], f);
    p->maps = my_str_to_world_array(f->contenu);
    find_d(p, e);
    create_box(p);
    my_adventure_loop(p, e);
}
