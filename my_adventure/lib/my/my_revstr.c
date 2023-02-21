/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;

    while (i < j) {
        char a = str[i];
        str[i] = str[j];
        str[j] = a;
        i++;
        j--;
    }
    return (str);
}
