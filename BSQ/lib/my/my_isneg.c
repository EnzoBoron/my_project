/*
** EPITECH PROJECT, 2022
** my_isneg.c
** File description:
** is neg
*/

int my_putchar(char);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else if (n >= 0) {
        my_putchar('P');
    }
}
