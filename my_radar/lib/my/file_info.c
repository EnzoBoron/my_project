/*
** EPITECH PROJECT, 2022
** struct
** File description:
** my_struct
*/

#include "my.h"

int how_many_letter(char *pathfile, get_element *element)
{
    int i = 0;
    int fd_sec;
    char buf[1];

    fd_sec = open(pathfile, O_RDONLY);
    if (fd_sec == -1) {
        my_putstr("Erreur Open");
        return 84;
    }
    for (; read(fd_sec, buf, 1) != 0; i++);
    close(fd_sec);
    return i;
}

int file_info(char *pathfile, get_element *element)
{
    int i = 0;
    int fd;
    char buf[1];

    element->pathfile = pathfile;
    if (how_many_letter(pathfile, element) == 84)
        return 84;
    element->number_letter = how_many_letter(pathfile, element);
    element->contenu = malloc(sizeof(char) * (element->number_letter + 1));
    fd = open(pathfile, O_RDONLY);
    for (i = 0; read(fd, buf, 1) != 0; i++)
        element->contenu[i] = buf[0];
    element->contenu[i] = '\0';
    close(fd);
}
