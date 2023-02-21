/*
** EPITECH PROJECT, 2022
** B-CPE-101-LIL-1-1-myprintf-enzo.boron
** File description:
** my_hex_lower_print_hash
*/

#include "../../include/my.h"

int my_hex_lower_print_hash(int x)
{
    my_putstr("0x");
    my_hex_lower_print(x);
    return 0;
}
