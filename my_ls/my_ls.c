/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-myls-enzo.boron
** File description:
** my_ls
*/

#include "include/mi.h"
#include "include/my.h"

void my_total(struct dirent *sd, char *pathdir)
{
    DIR *fd_total = opendir(pathdir);
    int i = 0;

    for (i = 0;(sd = readdir(fd_total)) != NULL; i++);
    my_putstr("total ");
    my_put_nbr(i * 4);
    my_putchar('\n');
    closedir(fd_total);
    return;
}

char *is_repo(char *pathdir)
{
    DIR *fd = opendir(pathdir);

    if (fd == NULL) {
        if (pathdir[0] != '/')
            pathdir = my_strcat("/", pathdir);
        closedir(fd);
        DIR *fd1 = opendir(&pathdir[1]);
        if (fd1 == NULL)
            exit(84);
    return &pathdir[1];
    } else
        return pathdir;

}

void redirection(char *pathdir, char **option, int cmp)
{
    pathdir = is_repo(pathdir);
    if (!option[1] || cmp == 0)
        my_ls_no_arg(pathdir);
    for (int i = 1; option[i] != NULL; i++) {
        if (option[i][0] == '-' && option[i][1] == 'l')
            my_ls_l(pathdir);
        if (option[i][0] == '-' && option[i][1] == 'a')
            my_ls_a(pathdir);
        if (option[i][0] == '-' && option[i][1] == 'r')
            my_ls_r(pathdir);
        if (option[i][0] == '-' && option[i][1] == 't')
            my_ls_a(pathdir);
    }
}

void my_ls(char **option)
{
    char *pathdir = "./";
    int i;
    int cmp = 0;

    for (i = 1; option[i] != NULL; i++) {
        if (option[i][0] != '-')
            pathdir = my_strcat(option[i], pathdir);;
        if (option[i][0] == '-')
            cmp = 1;
    }
    redirection(pathdir, option, cmp);
}

void main(int argc, char **argv)
{
    my_ls(argv);
}
