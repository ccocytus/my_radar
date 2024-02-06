/*
** EPITECH PROJECT, 2024
** my_radar.c
** File description:
** aircraft_settings.c
*/

#include "../include/my_prototypes.h"

int nb_aircrafts(FILE *file, char *lines, size_t size)
{
    int nb_aircrafts = 0;

    while (getline(&lines, &size, file) != -1) {
        if (lines[0] == 'A')
            nb_aircrafts++;
    }
    if (lines)
        free(lines);
    return (nb_aircrafts);
}

void seetting_aircraft(game_t *game, char *line)
{
    aircraft_t *aircraft = malloc(sizeof(aircraft_t));

    game->aircrafts[game->nb_a] = aircraft;
    aircraft->departure.x = my_getnbr(parser(line)[0]);
    aircraft->departure.y = my_getnbr(parser(line)[1]);
    aircraft->arrival.x = my_getnbr(parser(line)[2]);
    aircraft->arrival.y = my_getnbr(parser(line)[3]);
    aircraft->speed = my_getnbr(parser(line)[4]);
    aircraft->delay = my_getnbr(parser(line)[5]);
    aircraft->position.x = aircraft->departure.x;
    aircraft->position.y = aircraft->departure.y;
    aircraft->direction = way_head(aircraft);
    aircraft->sprite = sprite_aircraft(aircraft);
    aircraft->hitbox = hitbox_aircraft(aircraft);
    aircraft->position_case = position_case(aircraft->departure,
    aircraft->arrival);
    aircraft->rotation = rotation(aircraft);
    set_aircraft(aircraft, game);
    game->nb_a += 1;
}

sfVector2f way_head(aircraft_t *aircraft)
{
    sfVector2f direction_vector = {0, 0};
    sfVector2f displacement_vector = {0, 0};
    sfVector2f departure = aircraft->departure;
    sfVector2f arrival = aircraft->arrival;
    int speed = aircraft->speed;
    float hypothenus;

    direction_vector.x = arrival.x - departure.x;
    direction_vector.y = arrival.y - departure.y;
    hypothenus = sqrt((direction_vector.x * direction_vector.x) +
    (direction_vector.y * direction_vector.y));
    displacement_vector.x = direction_vector.x * speed / hypothenus / 40;
    displacement_vector.y = direction_vector.y * speed / hypothenus / 40;
    return (displacement_vector);
}

int check_landing(aircraft_t *aircraft)
{
    sfVector2f position = aircraft->position;
    sfVector2f arrival = aircraft->arrival;
    int result = get_result(aircraft->position_case, position, arrival);

    return result;
}

sfRectangleShape *hitbox_aircraft(aircraft_t *aircraft)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f hitbox_position = {0, 0};
    sfVector2f hitbox_size = {20, 20};

    aircraft->hitbox_color = sfTransparent;
    aircraft->hitbox_thickness = 2;
    aircraft->hitbox_position = hitbox_position;
    aircraft->hitbox_size = hitbox_size;
    aircraft->hitbox_rect.top = aircraft->hitbox_position.y;
    aircraft->hitbox_rect.left = aircraft->hitbox_position.x;
    aircraft->hitbox_rect.height = 20;
    aircraft->hitbox_rect.width = 20;
    return (hitbox);
}
