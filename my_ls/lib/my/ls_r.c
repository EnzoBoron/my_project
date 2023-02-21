/*
** EPITECH PROJECT, 2022
** ls
** File description:
** ls_r
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/mi.h"

int is_folder(struct dirent *sd, char *pathdir)
{
    struct stat *s;
    stat(pathdir, s);
    if (s->st_mode == DT_DIR || pathdir == "./")
        return 0;
    int nb_carac = my_strlen(pathdir);


    if (s->st_mode == DT_REG || s->st_mode == DT_UNKNOWN) {
        pathdir[nb_carac - 1] = '\0';
        my_putstr(&pathdir[2]);
        my_putchar('\n');
        exit(0);
    }
        return 0;
}

void is_folder_l(char *pathdir, struct dirent *sd)
{
    struct stat s;
    stat(pathdir, &s);
    stat(pathdir, &s);
    (sd->d_name[0] != '.') ? display_l(sd, s) : nothing();
    my_putstr(&pathdir[2]);
    exit(0);
}

void display_ls_r(char **tab)
{
    int a = 0;

    for (int i = 0; tab[i] != NULL; i++)
        if (tab[i][0] != '.')
            a++;
    for (a; a > 0; a--) {
        if (tab[a][0] != '.') {
            my_putstr(tab[a]);
            my_putchar('\n');
        }
    }
}

void assignation_valeur_r(char **ls_alpha, int i, struct dirent *sd)
{
    if ((sd->d_type == DT_DIR) || (sd->d_type == DT_REG)) {
            ls_alpha[i] = malloc(sizeof(char *) * (my_strlen(sd->d_name) + 1));
            for (int j = 0; sd->d_name[j] != '\0';  j++) {
                ls_alpha[i][j] = sd->d_name[j];
                ls_alpha[i][j + 1] = '\0';
        }
    }
}

void my_ls_r(char *pathdir)
{
    struct dirent *sd;
    DIR *fd = opendir(pathdir);
    DIR *fd_un = opendir(pathdir);
    int i;
    char **ls_alpha = NULL;

    my_erreur(fd_un, pathdir);
    for (i = 0 ; (sd = readdir(fd_un)) != NULL;)
        if (sd->d_name[0] != '.')
            i++;
    (i < 2) ? too_many_file(pathdir, sd, i) : nothing();
    if (i < 2)
        return;
        ls_alpha = malloc(sizeof(char) * (i + 1));
        closedir(fd_un);
    for (i = 0 ; (sd = readdir(fd)) != NULL;  i++)
        assignation_valeur_r(ls_alpha, i, sd);
    closedir(fd);
    display_ls_r(ls_alpha);
}
