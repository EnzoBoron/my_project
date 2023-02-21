/*
** EPITECH PROJECT, 2023
** simple_liken_list
** File description:
** add_node
*/

#include "../my.h"

liken_list *add_node_head(liken_list *list, int number)
{
    liken_list *tmp = malloc(sizeof(liken_list));
    tmp->number = number;
    tmp->next = list;
}

liken_list *add_node_tail(liken_list *list, int number)
{
    if (list == NULL) {
        list = add_node_head(list, number);
        return list;
    }
    liken_list *node = malloc(sizeof(liken_list));
    liken_list *tmp = list;
    node->number = number;
    node->next = NULL;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = node;
    return list;
}
