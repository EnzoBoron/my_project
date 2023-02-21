/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_ls_a
*/

#include "../../include/my.h"
#include "../../include/mi.h"

int nb_lettre(char *a)
{
    return my_strlen(a);
}

int my_erreur(DIR *fd, char *pathdir)
{
    if (fd == NULL) {
        my_putstr("my_ls: cannot access '");
        my_putstr(pathdir);
        my_putstr("': No such file or directory");
        exit(84);
    }
}

int my_ls_a(char *pathdir)
{
    struct dirent *sd;
    int i;
    DIR *fd = opendir(pathdir);

    my_erreur(fd, pathdir);
    if (fd < 0)
        my_putstr("open null");
    for (i = 0; (sd = readdir(fd)) != NULL;  i++) {
        my_putstr(sd->d_name);
        my_putstr("\n");
    }
    closedir(fd);
    return 0;
}
