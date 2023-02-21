/*
** EPITECH PROJECT, 2023
** my_testing
** File description:
** view_node
*/

#include "../my.h"

void display_liken_list(liken_list *list)
{
    liken_list *tmp = list;
    if (list == NULL) {
        my_putstr("Display list vide\n");
        return;
    }
    for (; tmp != NULL; tmp = tmp->next) {
        my_put_nbr(tmp->number);
        my_putstr(" -> ");
    }
    my_putstr("NULL\n");
}
