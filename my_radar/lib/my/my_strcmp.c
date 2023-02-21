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
    for (; s1[i] != s2[a] && s2[i] != s1[a]; i++){
    }
    for (; s2[a] != '\0'; a++) {
        if (s1[i] == s2[i])
            return 0;
        else {
            int res = s2[i] - s1[i];
            return res;
        }
    }
}
