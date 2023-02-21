/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-enzo.boron
** File description:
** opening_file
*/

#include "bsq.h"

int how_many_letter(char *pathfile)
{
    int i = 0;
    int fd;
    char buf[1];

    fd = open(pathfile, O_RDONLY);
    if (fd < 0)
        my_error("error opening file", 84);
    for (; read(fd, buf, 1) == 1; i++);
    close(fd);
    return i;
}

int verification_file(char **str)
{
    int i = 0;
    int y = 0;

    for (; str[i] != NULL; i++)
        for (; str[i][y] != '\0'; y++);
    return i;
}

char *assignation_valeur(int fd, char *buf, char *str)
{
    int i = 0;

    for (; read(fd, buf, 1) == 1; i++)
        str[i] = buf[0];
    str[i] = '\0';
    return str;
}

void first_line(char *pathfile)
{
    char buf[1];
    int i = 0;
    int fd_next = open(pathfile, O_RDONLY);
    for (; read(fd_next, buf, 1) != '0'; i++)
        if (buf[0] == '\n') {
            close(fd_next);
        }
}
