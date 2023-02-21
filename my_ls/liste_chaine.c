/*
** EPITECH PROJECT, 2022
** ls
** File description:
** liste_chaine
*/

#include "include/mi.h"
#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

void display_list(list_t *list)
{

    for (list_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        printf("%s\n", tmp->name);
    }
}

list_t *add_node(char *str)
{
    list_t *t;
    t = malloc(sizeof(list_t));
    t->name = str;
    t->next = NULL;
    return t;
}

void link_node(list_t **list, list_t *t)
{
    list_t *tmp = (*list);
    if ((*list) == NULL) {
        (*list) = t;
        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = t;
}
