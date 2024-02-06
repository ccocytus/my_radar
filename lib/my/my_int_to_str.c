/*
** EPITECH PROJECT, 2024
** int_to_string.c
** File description:
** char *
*/

#include <stdlib.h>
#include "my.h"

int rev_number(int nb)
{
    int a = 0;
    int b = 0;

    for (; nb > 0;) {
        a = nb % 10;
        nb = nb / 10;
        b *= 10;
        b += a;
    }
    return b;
}

int numbersize(int nb)
{
    int i = 0;

    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return i;
}

char *my_int_to_str(int nb)
{
    char *result;
    int reverse_nb;
    int size;
    int i = 0;

    result = malloc(sizeof(char) * (size + 1));
    result[0] = '\0';
    if (nb == 0)
        return "0";
    size = numbersize(nb);
    reverse_nb = rev_number(nb);
    while (i < size) {
        result[i] = (reverse_nb % 10) + '0';
        result[i + 1] = '\0';
        reverse_nb = reverse_nb / 10;
        i++;
    }
    return result;
}
