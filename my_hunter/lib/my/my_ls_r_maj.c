/*
** EPITECH PROJECT, 2022
** my
** File description:
** my_ls_r_maj
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "../../include/my.h"
#include <stdio.h>

void sub_folder(char *pathdir)
{
    struct dirent *sd2;

    DIR *fd2 = opendir(pathdir);
    if (fd2 < 0)
        my_putstr("open null");
        my_putchar('\n');
        for (int i = 0; (sd2 = readdir(fd2)) != NULL;  i++) {
                printf("%s", sd2->d_name);
            if (i == 5) {
                my_putchar('\n');
                i = 0;
            }
        }
    closedir(fd2);
}

int my_ls_r_maj(char *pathdir)
{
    struct dirent *sd;

    DIR *fd = opendir(pathdir);
    if (fd < 0)
        my_putstr("open null");

    for (int i = 0; (sd = readdir(fd)) != NULL; i++) {
        if (sd->d_type == DT_DIR)
            sub_folder(sd->d_name);
        if (sd->d_type == DT_REG){
            my_putstr(sd->d_name);
            my_putstr("   ");
        }
    }
    closedir(fd);
    return 0;
}
