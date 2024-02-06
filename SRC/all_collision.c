/*
** EPITECH PROJECT, 2024
** all_collision.c
** File description:
** my_radar
*/

#include "../include/my_prototypes.h"

int collision_top_left(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x - 20 / 2;
    int ry = aircraft->position.y - 20 / 2;
    int top_left = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (top_left);
}

int collision_top_right(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x + 20 / 2;
    int ry = aircraft->position.y - 20 / 2;
    int top_right = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (top_right);
}

int collision_bottom_left(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x - 20 / 2;
    int ry = aircraft->position.y + 20 / 2;
    int bottom_left = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (bottom_left);
}

int collision_bottom_right(game_t *game, aircraft_t *aircraft, int i)
{
    int cx = game->towers[i]->position.x;
    int cy = game->towers[i]->position.y;
    int rx = aircraft->position.x + 20 / 2;
    int ry = aircraft->position.y + 20 / 2;
    int bottom_right = sqrt((cx - rx) * (cx - rx) + (cy - ry) * (cy - ry));

    return (bottom_right);
}
