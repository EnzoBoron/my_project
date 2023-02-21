/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest ,char const *src)
{
    int nb = my_strlen(dest);
    int i = 0;
    int a = 0;

    for (; src[i] != '\0'; i++) {
        dest[nb + i] = src[i];
    }
    dest[nb + i] = '\0';
    return dest;
}
