/*
** EPITECH PROJECT, 2022
** my_strupcase.c
** File description:
** uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;
    int a = 0;

    if (str[i] - 32 <= str[i] + 32) {
        return str;
    }
    if (str[i] >= 48 && str[i] <= 57){
        return str;
    }
    for (;str[i] != '\0'; i++){
        str[i] = str[i] - 32;
    }
    return str;
}
