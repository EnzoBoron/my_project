/*
** EPITECH PROJECT, 2023
** my_testing
** File description:
** setting_node
*/

#include "../my.h"

int repete_nbumber_element(liken_list *list, int number)
{
    liken_list *tmp = list;
    int repete = 0;
    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->number == number)
            repete++;
    return repete;
}

int number_of_element(liken_list *list)
{
    liken_list *tmp = list;
    int number_element = 0;
    for (; tmp != NULL; tmp = tmp->next, number_element++);
    return number_element;
}

int is_empty(liken_list *list)
{
    if (list != NULL)
        return 1;
    return 0;
}