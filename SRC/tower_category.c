/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** tower.c
*/

#include "../include/my_prototypes.h"

int towers_i_file(FILE *file, char *lines, size_t size)
{
    int towers = 0;

    while (getline(&lines, &size, file) != -1) {
        if (lines[0] == 'T')
            towers++;
    }
    if (lines)
        free(lines);
    return (towers);
}

void setting_tower(game_t *game, char *line)
{
    tower_t *tours = malloc(sizeof(tower_t));

    game->towers[game->nb_t] = tours;
    tours->position.x = my_getnbr(parser(line)[0]);
    tours->position.y = my_getnbr(parser(line)[1]);
    tours->radius = my_getnbr(parser(line)[2]);
    tours->sprite = tower_sprite(tours);
    tours->area = tower_area(tours);
    sfSprite_setOrigin(tours->sprite,
    (sfVector2f) {60 / 2, 60 / 2});
    game->nb_t += 1;
}

sfCircleShape *tower_area(tower_t *tower)
{
    sfCircleShape *area = sfCircleShape_create();
    sfVector2f area_position;
    sfVector2f tower_position = tower->position;

    area_position.x = tower_position.x;
    area_position.y = tower_position.y;
    tower->area_color = sfBlue;
    tower->area_thickness = 2;
    tower->area_position = area_position;
    return (area);
}

void area_towers(sfRenderWindow *win, game_t *game, int i)
{
    sfRenderWindow_drawCircleShape(win, game->towers[i]->area, NULL);
}

void in_tower_area(game_t *game, aircraft_t *aircraft)
{
    int top_left;
    int top_right;
    int bottom_left;
    int bottom_right;
    int radius;

    for (int i = 0; i < game->nb_t; i++) {
        radius = RADIUS(game->towers[i]->radius);
        top_left = collision_top_left(game, aircraft, i);
        top_right = collision_top_right(game, aircraft, i);
        bottom_left = collision_bottom_left(game, aircraft, i);
        bottom_right = collision_bottom_right(game, aircraft, i);
        if (top_left <= radius || top_right <= radius ||
        bottom_left <= radius || bottom_right <= radius) {
            aircraft->nb_towers = 1;
            return;
        }
        aircraft->nb_towers = 0;
    }
}
