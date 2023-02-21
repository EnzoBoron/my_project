/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_ls_l
*/

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>

#include <stdlib.h>
#include "../../include/my.h"

void display_l(struct dirent *sd, struct passwd *pw, struct stat s)
{
    my_put_nbr(s.st_size);
    my_putchar(' ');
    my_putstr(pw->pw_name);
    my_putchar(' ');
    my_putstr(pw->pw_name);
    my_putchar(' ');
    my_putstr(sd->d_name);
    my_putchar(' ');
    my_putchar('\n');
    if (sd->d_type == DT_REG)
        my_putstr("- ");
    if (sd->d_type == DT_DIR)
        my_putstr("d ");
}

int my_ls_l(char *pathdir)
{
    struct dirent *sd;
    struct passwd *pw;
    struct stat s;

    DIR *fd = opendir(pathdir);
    if (fd < 0)
        my_putstr("open null");

    while ((sd = readdir(fd)) != NULL && (pw = getpwnam("nawaak")) != NULL) {
        if (sd->d_name[0] != '.') {
            stat(sd->d_name, &s);
            display_l(sd, pw, s);

        }
    }
    closedir(fd);
    return 0;
}
