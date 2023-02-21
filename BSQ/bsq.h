/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-enzo.boron
** File description:
** my
*/

#ifndef BSQ_H
    #define BSQ_H
    #include "include/my.h"
    #include "include/my_string.h"
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>

    int nothing(void);
    char **my_str_to_world_array_bsq(char *str);
    int how_many_letter(char *pathfile);
    int vrification_file(char **str);
    char *assignation_valeur(int fd, char *buf, char *str);
    void first_line(char *pathfile);
    char **transform_in_number(char **tab);
    void find_the_bigger_square(char **tab, int *coordonees);
    void conditionfind_the_bigger_square(char **, int *, int, int);
    char **transform_in_original(char **tab);
    char **put_caractere_x(char **tab, int *coor);
    int min(int x_un, int y_un, int xy_un);
    void my_free(char **my_str);
#endif /* !MY_H_ */
