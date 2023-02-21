/*
** EPITECH PROJECT, 2022
** my_str_islower.c
** File description:
** str_islower
*/

int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int i = 0;
    int a = 0;
    int b = 0;

    for (; str[i] != '\0'; i++){
        if (str[i] >= 65 && str[i] <= 90)
            a++;
        else
            b++;
    }
    if (b == my_strlen(str))
        return 1;
    return 0;
}
