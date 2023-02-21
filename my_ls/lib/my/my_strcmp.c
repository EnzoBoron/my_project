/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare a string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int a = 0;
    int b = 0;

    for (; s2[i] != '\0' && s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            b++;
    }
    return b;
}
