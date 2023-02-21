/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef _my_h_
    #define _my_h_
    typedef int (*ptr_int)();
    int my_compute_power_rec(int, int);
    int my_compute_square_root(int);
    int my_find_prime_sup(int);
    int my_getnbr(char const *);
    int my_isneg(int);
    int my_is_prime(int);
    void my_putchar(char);
    int my_putchar_print(int);
    void my_put_nbr(int);
    int my_put_nbr_print(int);
    int my_putstr(char const *str);
    int my_putstr_print(char const *str);
    char *my_revstr(char *str);
    int my_showmem(char const *str, int size);
    int my_showstr(char const *str);
    void my_sort_int_array(int *tab, int size);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest ,char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isnum_print(int const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_strncmp(char const *s1 ,char const *s2 , int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str ,char const *to_find);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    int diviser(int nb, int a);
    void display_octal(int save[100], int i);
    int my_octet_print(int x);
    int diviser(int nb, int a);
    int my_put_usigned_print(int nb);
    int my_positive_nbr_print(int a);
    int my_hex_upper_print(long int x);
    int big_hex(long int d, long int r, int x, int p);
    int display_hex(long int nb, long int plus);
    int puissance(long int x, long int nb, int base);
    int my_hex_lower_print(long int x);
    int my_double_print(double a);
    int my_adress_memory_print(void *a);
    int my_binary_print(int x);
    int my_pourcentage_n(void *a, int argv, char **argc);
    int my_hex_lower_print_hash(int x);
    int my_hex_upper_print_hash(int x);
    int my_octet_print_hash(int x);
    char **my_str_to_word_array(char const *str);
    char **malloc_string(char const *str);
    int comte_words(char const *str);
    int is_alpha(char i);
    int my_ls_a(char *pathdir);
    void my_ls_l(char *pathdir);
    int my_ls_r_maj(char *pathdir);
    char *transform_in_simple_array(char **option);
    int nothing(void);
    void my_stremove(char *str, int indice);

#endif /* _my_h_ */
