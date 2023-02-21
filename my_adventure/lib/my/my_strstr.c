/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** strstr
*/

int my_strlen(char const *str);

char *my_strstr(char *str ,char const *to_find)
{
    int i = 0;
    int a = 0;

    for (; str[i] != to_find[a]; i++) {}
    for (; str[i] == str[a]; i++) {
        str[a] = str[i];
        a++;
    }
    return &str[i];
}
