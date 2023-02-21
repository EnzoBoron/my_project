/*
** EPITECH PROJECT, 2022
** ls
** File description:
** ls_no_arg
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/mi.h"

void display_ls_no_arg(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] != '.') {
        my_putstr(tab[i]);
        my_putstr("  ");
        }
    }
}

void assignation_valeur(char **ls_alpha, int i, struct dirent *sd)
{
    if ((sd->d_type == DT_DIR) || (sd->d_type == DT_REG)) {
        ls_alpha[i] = malloc(sizeof(char *) * (my_strlen(sd->d_name) + 1));
            for (int j = 0; sd->d_name[j] != '\0';  j++) {
                ls_alpha[i][j] = sd->d_name[j];
                ls_alpha[i][j + 1] = '\0';
        }
    }
}

void my_ls_no_arg(void)
{
    struct dirent *sd;
    DIR *fd = opendir(".");
    DIR *fd_un = opendir(".");
    int i;
    char **ls_alpha = NULL;

    for (i = 0 ; (sd = readdir(fd_un)) != NULL;  i++);
        ls_alpha = malloc(sizeof(char) * (i + 1));
        closedir(fd_un);
    for (i = 0 ; (sd = readdir(fd)) != NULL;  i++) {
        assignation_valeur(ls_alpha, i, sd);
    }
    ls_alpha[i + 1] = NULL;
    closedir(fd);
    display_ls_no_arg(ls_alpha);
}
