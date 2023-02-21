/*
** EPITECH PROJECT, 2022
** my_str_isprintable.c
** File description:
** str_isprintable
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 32 && str[i] <= 126) {
        } else
            return 1;
    }
    return 0;
}
