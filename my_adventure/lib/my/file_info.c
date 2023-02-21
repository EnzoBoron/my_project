/*
** EPITECH PROJECT, 2022
** struct
** File description:
** my_struct
*/

#include "my.h"
#include <string.h>

void how_many_letter_line(get_element *element, char **maps, int y)
{
    element->number_carctere_line = 0;
    for (int x = 0; x != y; x++)
        element->number_carctere_line += my_strlen(maps[x]);
}

int how_many_letter(char *pathfile, get_element *element)
{
    int i = 0;
    int fd_sec;
    char buf[1];

    fd_sec = open(pathfile, O_RDWR);
    for (; read(fd_sec, buf, 1) != 0; i++);
    close(fd_sec);
    return i;
}

void file_info(char *pathfile, get_element *element)
{
    int i = 0;
    int fd;
    char buf[1];

    element->pathfile = pathfile;
    element->number_letter = how_many_letter(pathfile, element);
    element->contenu = malloc(sizeof(char) * (element->number_letter + 1));
    fd = open(pathfile, O_RDWR);
    if (&fd == NULL) {
        my_putstr("Erreur \"OPEN\"");
        exit(84);
    }
    for (i = 0; read(fd, buf, 1) != 0; i++)
        element->contenu[i] = buf[0];
    element->contenu[i] = '\0';
    close(fd);
}

char *remove_text(int x, char letter, get_element *element, char *pathfile)
{
    int i = 0;
    char buf[1];
    char *my_map = malloc(sizeof(char)*10000);
    int fd = open(pathfile, O_RDWR);
    for (i = 0; read(fd, buf, 1) != 0; i++)
        my_map[i] = buf[0];
    my_map[i] = '\0';
    for (i = element->number_carctere_line; my_map[i] != '\0'; i++)
        if (my_map[i] == letter) {
            my_map[i] = ' ';
            break;
        }
    FILE *f = fopen(pathfile,"w");
    fprintf(f, my_map);
    fclose(f);
    free(my_map);
    close(fd);
}

void reset_map(get_element *element, char *mapsOriginal, char *maps)
{
    int i = 0;
    char buf[1];
    char *my_map = malloc(sizeof(char)*10000);
    int fd = open(mapsOriginal, O_RDWR);
    for (i = 0; read(fd, buf, 1) != 0; i++)
        my_map[i] = buf[0];
    my_map[i] = '\0';
    FILE *f = fopen(maps,"w");
    fprintf(f, my_map);
    fclose(f);
    free(my_map);
    close(fd);
}
