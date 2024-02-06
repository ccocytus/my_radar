/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** the first
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *copy_str, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        copy_str[i] = src[i];
    }
    copy_str[i] = '\0';
    return copy_str;
}

char *my_strdup(char const *src)
{
    char *copy_str;

    copy_str = malloc(sizeof(src + 1));
    my_strcpy(copy_str, src);
    return copy_str;
}
