/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** aircraft_hitboxes
*/

#include "../include/my_prototypes.h"

void display_grid(sfRenderWindow *win, game_t *game)
{
    if (game->key_g == 1) {
        for (int i = 0; i < 100; i++) {
            sfRenderWindow_drawRectangleShape
            (win, game->grid[i]->rectangle, NULL);
        }
    }
}

void prin_grid(game_t *game, int i)
{
    grid_base_t *grid = game->grid[i];

    sfRectangleShape_setFillColor(grid->rectangle, grid->fill_color);
    sfRectangleShape_setOutlineColor(grid->rectangle, grid->outline_color);
    sfRectangleShape_setOutlineThickness
    (grid->rectangle, grid->outline_thickness);
    sfRectangleShape_setSize(grid->rectangle, grid->size);
    sfRectangleShape_setPosition(grid->rectangle, grid->position);
}

void grid(game_t *game)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < 100; i++) {
        game->grid[i] = malloc(sizeof(grid_base_t));
        game->grid[i]->rectangle = sfRectangleShape_create();
        game->grid[i]->fill_color = sfTransparent;
        game->grid[i]->outline_color = sfWhite;
        game->grid[i]->outline_thickness = 1;
        game->grid[i]->size =
        (sfVector2f) {1920 / sqrt(100), 1080 / sqrt(100)};
        game->grid[i]->position = (sfVector2f) {j, k};
        j += 1920 / sqrt(100);
        if (i % (int)(sqrt(100)) == sqrt(100) - 1) {
            k += 1080 / sqrt(100);
            j = 0;
        }
        prin_grid(game, i);
    }
}

int position_case(sfVector2f departure, sfVector2f arrival)
{
    if (arrival.x > departure.x && arrival.y > departure.y)
        return (1);
    if (arrival.x < departure.x && arrival.y > departure.y)
        return (2);
    if (arrival.x < departure.x && arrival.y < departure.y)
        return (3);
    if (arrival.x > departure.x && arrival.y < departure.y)
        return (4);
    if (arrival.x > departure.x && arrival.y == departure.y)
        return (5);
    if (arrival.x == departure.x && arrival.y > departure.y)
        return (6);
    if (arrival.x < departure.x && arrival.y == departure.y)
        return (7);
    if (arrival.x == departure.x && arrival.y < departure.y)
        return (8);
}

int rotation(aircraft_t *aircraft)
{
    float angle;

    angle = atan2(aircraft->direction.y, aircraft->direction.x);
    angle *= 180 / 3.14159265359;
    if (angle < 0)
        angle += 360;
    return (angle);
}
