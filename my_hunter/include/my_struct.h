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
    #include "my_struct.h"
    #include "my.h"
    typedef struct get_element {
        char *pathfile;
        char *contenu;
        int number_letter;
    }get_element;
    int my_putstr(char const *);
    char* my_strcpy(char* destination, const char* source);

#endif /* !MY_H_ */
