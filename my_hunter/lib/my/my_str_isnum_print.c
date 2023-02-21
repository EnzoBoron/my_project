/*
** EPITECH PROJECT, 2022
** my_str_isnum.c
** File description:
** str_isnum
*/

int my_str_isnum_print(int const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++){
        if (str[i] >= 48 && str[i] <= 57) {
        } else {
            return 1;
        }
    }
    return 0;
}
