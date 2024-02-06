/*
** EPITECH PROJECT, 2024
** my_strappend
** File description:
** char *
*/

#include "my.h"
#include <stdlib.h>

char *my_strappend(char *str, char src)
{
    int i = my_strlen(str);

    str[i] = src;
    str[i + 1] = '\0';
    return (str);
}

char *add_to_tab(char *line, int i)
{
    int j = i;
    char *res = malloc(sizeof(char) * 5);

    res[0] = '\0';
    while (line[j] != ' ' && line[j] != '\n') {
        my_strappend(res, line[j]);
        j++;
    }
    return (res);
}
