/*
** EPITECH PROJECT, 2022
** my_compute_power_rec.c
** File description:
** rec
*/

int my_compute_power_rec(int nb, int p)
{
    int arg_a = nb;

    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        return (arg_a * my_compute_power_rec(nb, p - 1));
    }
}
