/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-myls-enzo.boron
** File description:
** my_ls_l
*/

#include "../../include/my.h"
#include "../../include/mi.h"

void permition(struct stat s, struct dirent *sd)
{
    (s.st_mode & S_IFREG) ? my_putstr("-") : my_putchar('d');
    (s.st_mode & S_IRUSR) ? my_putchar('r') : my_putchar('-');
    (s.st_mode & S_IWUSR) ? my_putchar('w') : my_putchar('-');
    (s.st_mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (s.st_mode & S_IRGRP) ? my_putchar('r') : my_putchar('-');
    (s.st_mode & S_IWGRP) ? my_putchar('w') : my_putchar('-');
    (s.st_mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (s.st_mode & S_IROTH) ? my_putchar('r') : my_putchar('-');
    (s.st_mode & S_IWOTH) ? my_putchar('w') : my_putchar('-');
    (s.st_mode & S_IXOTH) ? my_putchar('x') : my_putchar('-');
    my_putchar(' ');
}

void month(struct stat s)
{
    char *date = &ctime(&s.st_mtime)[4];
    date[12] = '\0';
    my_putstr(date);
}

void display_name(struct stat s)
{
    struct passwd *pw;
    struct passwd *pw_groupe;
    (pw = getpwuid(s.st_uid));
    (pw_groupe = getpwuid(s.st_gid));
    my_putstr(pw->pw_name);
    my_putchar(' ');
    my_putstr(pw_groupe->pw_name);
    my_putchar(' ');
}

void display_l(struct dirent *sd, struct stat s)
{
    permition(s, sd);
    my_put_nbr(s.st_nlink);
    my_putchar(' ');
    display_name(s);
    my_put_nbr(s.st_size);
    my_putchar(' ');
    month(s);
    my_putchar(' ');
    my_putstr(sd->d_name);
    my_putchar(' ');
    my_putchar('\n');
}

void my_ls_l(char *pathdir)
{
    struct dirent *sd;
    struct stat s;
    DIR *fd = opendir(pathdir);
    int nb_carac = my_strlen(pathdir);

    my_erreur(fd, pathdir);
    my_total(sd, pathdir);
    for (int i = 0;(sd = readdir(fd)) != NULL;)
        if (sd->d_name[0] != '.') {
            pathdir = my_strcat("/", pathdir);
            pathdir = my_strcat(sd->d_name, pathdir);
            stat(pathdir, &s);
            my_stremove(pathdir, nb_carac);
            (sd->d_name[0] != '.') ? display_l(sd, s) : nothing();
        }
    closedir(fd);
}
