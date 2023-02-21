/*
** EPITECH PROJECT, 2022
** ls
** File description:
** mi
*/

#ifndef _MI_H_
    #define _MI_H_
    #include <sys/types.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stddef.h>
    typedef struct list_t list_t;
    struct list_t {
        char *name;
        list_t *next;
    };
    list_t *add_node(char *str);
    void print_list(list_t *list);
    void display_list(list_t *list);
    void link_node(list_t **list, list_t *t);
    void trie_alphabetique(list_t *list, char *str1, char *str2);
    char **my_display_alphabetique(char **list);
    void tidy_number(char **tab);
    void tidy_letter(char **tab);
    void arrange_number(char **tab);
    void arrange_letter(char **tab);
    void my_ls_r(char *pathdir);
    void my_ls_no_arg(char *pathdir);
    void too_many_file(char *pathdir, struct dirent *sd, int i);
    void my_total(struct dirent *sd, char *pathdir);
    int my_erreur(DIR *fd, char *pathdir);
    int is_folder(struct dirent *sd, char *pathdir);
    void is_folder_l(char *pathdir, struct dirent *sd);
    void permition(struct stat s, struct dirent *sd);
    void month(struct stat s);
    void display_name(struct stat s);
    void display_l(struct dirent *sd, struct stat s);
#endif /* _MI_H_ */
