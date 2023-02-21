/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** reproduice strncmp
*/

int my_strncmp(char const *s1 ,char const *s2 , int n)
{
    int a = 0;

    for (; s1[n] == s2[a] || s2[n] == s1[a]; n++) {
        a++;
        return a;
    } if (s1[n] < s2[a] || s1[n] > s2[a]) {
        int res = s2[n] - s1[n];
        return res;
    }
}
