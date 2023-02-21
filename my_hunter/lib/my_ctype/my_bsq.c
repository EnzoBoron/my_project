/*
** EPITECH PROJECT, 2022
** B-CPE-110-LIL-1-1-BSQ-enzo.boron
** File description:
** my_bsq
*/

int my_bsq(char a)
{
    if (a == '.' || (a >= '0' && a <= '9') || a == 'o' || a == 'x')
        return 1;
    return 0;
}
