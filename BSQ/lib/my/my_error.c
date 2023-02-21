/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-enzo.boron
** File description:
** my_error
*/

#include "my.h"

void my_error(char *message_error, int my_return)
{
    my_putstr(message_error);
    exit(my_return);
}
