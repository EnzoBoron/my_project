/*
** EPITECH PROJECT, 2022
** ls
** File description:
** ls_no_arg
*/

#include "../../include/my.h"
#include "../../include/mi.h"

void display_ls_no_arg(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] != '.') {
        my_putstr(tab[i]);
        my_putchar('\n');
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
        ls_alpha[i + 1] = NULL;
    }
}

void many_arg(int i, char *pathdir)
{
    DIR *fd_deux = opendir(pathdir);
    struct dirent *sd;

    for (; (sd = readdir(fd_deux)) != NULL;)
        if (sd->d_name[0] != '.') {
            my_putstr(sd->d_name);
            closedir(fd_deux);
        }
        return;
    if (i < 1) {
        closedir(fd_deux);
        return;
    }
}

void too_many_file(char *pathdir, struct dirent *sd, int i)
{
    DIR *fd_many = opendir(pathdir);

    for (int i = 0; (sd = readdir(fd_many)) != NULL; i++) {
        if (sd->d_name[0] != '.')
            my_putstr(sd->d_name);
    }
    if (i == 1)
        my_putchar('\n');
    return;
    closedir(fd_many);

}

void my_ls_no_arg(char *pathdir)
{
    struct dirent *sd;
    int i;
    char **ls_alpha = NULL;

    DIR *fd = opendir(pathdir);
    DIR *fd_un = opendir(pathdir);
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
        assignation_valeur(ls_alpha, i, sd);
    closedir(fd);
    display_ls_no_arg(ls_alpha);
}
