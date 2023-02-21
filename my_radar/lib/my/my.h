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
    typedef struct get_element {
        char *pathfile;
        char *contenu;
        int number_letter;
    }get_element;
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
    char **my_str_to_world_array(char *str);
    int file_info(char *pathfile, get_element *element);
    int my_strlen(char const *str);
    char *my_strchr(const char *string, int searchedChar);

#endif /* _my_h_ */
