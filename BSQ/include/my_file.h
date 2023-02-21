/*
** EPITECH PROJECT, 2022
** struct
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include "../my/my.h"
    typedef struct files {
        char *pathfile;
        char *contenu;
        int number_letter;
    }files;
    int my_putstr(char const *);
    char **my_str_to_world_array(char *str);

#endif /* !MY_H_ */
