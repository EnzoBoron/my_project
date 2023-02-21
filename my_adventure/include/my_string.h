/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** my_string
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_
    #include <stdlib.h>
    char *my_strcat(char *dest ,char const *src);
    int my_strcmp(const char* str1, const char* str2);
    char* my_strcpy(char* destination, const char* source);
    char *my_strchr(const char *string, int searchedChar);
    int my_strlen(const char *str);
    int my_putstr(const char*);
    void my_put_nbr(int);

#endif /* !MY_STRING_H_ */
