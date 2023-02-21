/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** number
*/

int my_putchar_print(int);

int my_put_usigned_print(int nb)
{
    if (nb < 0) {
        return 1;
    }
    if (nb > 9) {
        my_put_usigned_print(nb / 10);
        my_put_usigned_print(nb % 10);
    } else {
        my_putchar_print(nb + 48);
    }
    return 0;
}
