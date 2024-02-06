/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** position_check.c
*/

#include "../include/my_prototypes.h"


int check_case_1(sfVector2f position, sfVector2f arrival)
{
    if (position.x > arrival.x) {
        if (position.y > arrival.y) {
            return 1;
        }
    }
    return 0;
}

int check_case_2(sfVector2f position, sfVector2f arrival)
{
    if (position.x < arrival.x) {
        if (position.y > arrival.y) {
            return 1;
        }
    }
    return 0;
}

int check_case_3(sfVector2f position, sfVector2f arrival)
{
    if (position.x < arrival.x) {
        if (position.y < arrival.y) {
            return 1;
        }
    }
    return 0;
}

int check_case_4(sfVector2f position, sfVector2f arrival)
{
    if (position.x > arrival.x) {
        if (position.y < arrival.y) {
            return 1;
        }
    }
    return 0;
}

int get_result(int position_case, sfVector2f position, sfVector2f arrival)
{
    switch (position_case) {
        case 1:
            return check_case_1(position, arrival);
        case 2:
            return check_case_2(position, arrival);
        case 3:
            return check_case_3(position, arrival);
        case 4:
            return check_case_4(position, arrival);
        case 5:
            return check_case_5(position, arrival);
        case 6:
            return check_case_6(position, arrival);
        case 7:
            return check_case_7(position, arrival);
        case 8:
            return check_case_8(position, arrival);
        default:
            return 1;
    }
}
