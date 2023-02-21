/*
** EPITECH PROJECT, 2022
** B-PSU-100-LIL-1-1-sokoban-enzo.boron
** File description:
** is_alpha
*/

int is_alpha(char a)
{
    if ((a >= '0' && a <= '9') || (a >= 'a' && a <= 'z')
    || (a >= 'A' && a <= 'Z') || a == '#' || a == 32)
        return 1;
    return 0;
}
