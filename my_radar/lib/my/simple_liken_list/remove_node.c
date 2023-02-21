/*
** EPITECH PROJECT, 2023
** my_testing
** File description:
** remove_node
*/

#include "../my.h"

liken_list *free_list(liken_list *list)
{
    liken_list *begin = NULL;
    if (list == NULL) {
        my_putstr("Don't free none list\n");
        return list;
    }
    for (liken_list *tmp = list; tmp != NULL;) {
        begin = tmp;
        tmp = tmp->next;
        free(begin);
    }
    return list;
}

liken_list *remove_first_node(liken_list *list)
{
    liken_list *begin = list;
    list = list->next;
    free(begin);
    return list;
}

liken_list *remove_last_node(liken_list *list)
{
    liken_list *tmp = list;
    if (number_of_element(list) == 1) {
        tmp = NULL;
        tmp->next = NULL;
    }
    for (; tmp->next->next != NULL; tmp = tmp->next);
    tmp->next = NULL;
    tmp = NULL;
    return list;
}
