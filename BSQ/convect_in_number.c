/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-enzo.boron
** File description:
** convect_in_number
*/

#include "bsq.h"

char **transform_in_number(char **tab)
{
    for (int x = 0; tab[x] != NULL; x++) {
        for (int y = 0; tab[x][y] != '\0'; y++) {
            tab[x][y] = (tab[x][y] == '.') ? '1' : '0';
        }
    }
    return tab;
}

void find_the_bigger_square(char **tab, int *coordonees)
{
    for (int y = 1; tab[y] != NULL; y++) {
        for (int x = 0; tab[y][x] != '\0'; x++) {
            conditionfind_the_bigger_square(tab, coordonees, x, y);
        }
    }
}

void conditionfind_the_bigger_square(char **tab, int *coordonees, int x, int y)
{
    int tmp = 0;

    if ((x == 0 || y == 1) || (x == 0 && y == 1));
    else if (tab[y][x] > '0' && tab[y][x] <= '9') {
        tab[y][x] = 1 + min(tab[y][x - 1], tab[y - 1][x], tab[y - 1][x - 1]);
        tmp = (tab[y][x] - '0');
    } if (tmp > coordonees[0] && tmp < 100000) {
        coordonees[0] = tmp;
        coordonees[1] = x;
        coordonees[2] = y;
    }
}

char **transform_in_original(char **tab)
{
    for (int x = 0; tab[x] != NULL; x++) {
        for (int y = 0; tab[x][y] != '\0'; y++) {
            tab[x][y] = (tab[x][y] == '0') ? 'o' : '.';
        }
    }
    return tab;
}

char **put_caractere_x(char **tab, int *coor)
{
    for (int y = coor[2] - (coor[0] - 1); y <= (coor[2]); y++) {
        for (int x = coor[1] - (coor[0] - 1); x <= (coor[1]); x++) {
            tab[y][x] = 'x';
        }
    }
    return tab;
}
