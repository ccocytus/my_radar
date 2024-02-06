/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** position_check.c
*/

#include "../include/my_prototypes.h"

int check_case_5(sfVector2f position, sfVector2f arrival)
{
    if (position.x >= arrival.x) {
        return 1;
    }
    return 0;
}

int check_case_6(sfVector2f position, sfVector2f arrival)
{
    if (position.y >= arrival.y) {
        return 1;
    }
    return 0;
}

int check_case_7(sfVector2f position, sfVector2f arrival)
{
    if (position.x <= arrival.x) {
        return 1;
    }
    return 0;
}

int check_case_8(sfVector2f position, sfVector2f arrival)
{
    if (position.y <= arrival.y) {
        return 1;
    }
    return 0;
}
