/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef _my_h_
    #define _my_h_
    #include <stdlib.h>
    typedef int (*ptr_int)();
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct get_element {
        char *pathfile;
        char *contenu;
        int number_letter;
        int number_carctere_line;
        int who_is_my_carac;
    }get_element;

    typedef struct around {
        char pos;
        char up;
        char d_up;
        char left;
        char d_left;
        char ri;
        char d_ri;
        char down;
        char d_down;
    } around;

    int my_putstr(char const *);
    int my_compute_power_rec(int, int);
    int my_compute_square_root(int);
    int my_find_prime_sup(int);
    int my_getnbr(char const *);
    int my_isneg(int);
    int my_is_prime(int);
    void my_putchar(char);
    void my_put_nbr(int);
    int my_putstr(char const *);
    char *my_revstr(char *);
    int my_showmem(char const *, int);
    int my_showstr(char const *);
    void my_sort_int_array(int *, int);
    char *my_strcapitalize(char *);
    void my_swap(int *, int *);
    int comte_words(char const *);
    char *transform_in_simple_array(char **);
    int nothing(void);
    char **my_str_to_world_array(char *);
    void file_info(char *, get_element *);
    int my_strlen(char const *);
    char *my_strcpy(char *, char const *);
    char *my_strchr(const char *, int );
    void how_many_letter_line(get_element *, char**, int);
    char * transform_in_char(int);

#endif /* _my_h_ */
