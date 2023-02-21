/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_ls_a
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

int nb_lettre(char *a)
{
    return my_strlen(a);
}

int my_ls_a(char *pathdir)
{
    struct dirent *sd;
    DIR *fd = opendir(pathdir);
    char **files;
    int i;
    int size = 0;

    if (fd < 0)
        my_putstr("open null");
    for (i = 0; (sd = readdir(fd)) != NULL;  i++) {
        my_putstr(sd->d_name);
        my_putstr("  ");
    }
    closedir(fd);
    return 0;
}
