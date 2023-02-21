/*
** EPITECH PROJECT, 2022
** cmp_word.c
** File description:
** cmp_word
*/

int cmp_char(char **av, int i, int j)
{
    int cmp;

    if (av[i][j] == 32)
        cmp++;
    return cmp;
}

int cmp_word(int ac, char **av)
{
    int cmp = 0;
    int a = 0;

    for (int i = 0; av[i] != 0; i++) {
        a = my_strlen(av[i]);
        if (av[i][a] == ' ')
            cmp++;
    }
    return cmp;
}
