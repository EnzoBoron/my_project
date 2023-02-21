/*
** EPITECH PROJECT, 2022
** my_strcapitalize.c
** File description:
** strcapitalize
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] - 32 == 0) {
            str[i + 1] = str[i + 1] - 32;
        }
        if (str[i] == str[0]) {
            str[0] = str[0] - 32;
        }
    }
    return str;
}
