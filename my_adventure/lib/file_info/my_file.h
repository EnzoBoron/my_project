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
    #include "../../include/my.h"
    #include "../../include/my_string.h"

    typedef struct get_element {
        char *pathfile;
        char *contenu;
        unsigned int number_letter;
    } get_element;

    int my_putstr(char const *);

#endif /* !MY_H_ */
