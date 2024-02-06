/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** aircraft_setting2
*/

#include "../include/my_prototypes.h"

void aircraft_collision(game_t *game, aircraft_t *aircraft_a, int i)
{
    aircraft_t *aircraft_b;

    for (int j = 0; j < game->nb_a; j++) {
        aircraft_b = game->aircrafts[j];
        if (i != j && aircraft_b->destroyed == 0 &&
        aircraft_b->nb_towers == 0 && aircraft_a->decollage == 1 &&
        aircraft_b->decollage == 1 && aircraft_a->aterri == 0 &&
        aircraft_b->aterri == 0)
            destroy_aircrafts(game, aircraft_a, aircraft_b);
    }
}

void render_hitboxes_aircrafts(game_t *game, sfRenderWindow *win,
    aircraft_t *aircraft)
{
    if (aircraft->decollage == 1 && aircraft->aterri == 0 &&
    aircraft->destroyed == 0) {
        sfRectangleShape_move(aircraft->hitbox, aircraft->position);
        if (aircraft->nb_towers == 0)
            aircraft->hitbox_color = sfRed;
        if (aircraft->nb_towers == 1)
            aircraft->hitbox_color = sfGreen;
        sfRectangleShape_setOutlineColor(aircraft->hitbox,
        aircraft->hitbox_color);
        sfRenderWindow_drawRectangleShape(win, aircraft->hitbox, NULL);
    }
}

void set_hitboxes_aircrafts(aircraft_t *aircraft)
{
    aircraft->hitbox_rect.left = aircraft->position.x;
    aircraft->hitbox_rect.top = aircraft->position.y;
    sfRectangleShape_setOrigin(aircraft->hitbox,
    (sfVector2f) {20 / 2, 20 / 2});
    sfRectangleShape_setPosition(aircraft->hitbox, aircraft->hitbox_position);
    sfRectangleShape_setFillColor(aircraft->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(aircraft->hitbox,
    aircraft->hitbox_thickness);
    sfRectangleShape_setSize(aircraft->hitbox, aircraft->hitbox_size);
}

void render_aircrafts(game_t *game, sfRenderWindow *win,
    aircraft_t *aircraft)
{
    if (aircraft->decollage == 1 && aircraft->aterri == 0 &&
    aircraft->destroyed == 0) {
        sfRenderWindow_drawSprite(win, aircraft->sprite, NULL);
    }
}

void aircrafts_move(game_t *game, aircraft_t *aircraft)
{
    if (aircraft->decollage == 1 && aircraft->aterri == 0 &&
    aircraft->destroyed == 0) {
        sfSprite_move(aircraft->sprite, aircraft->direction);
        aircraft->position.x += aircraft->direction.x;
        aircraft->position.y += aircraft->direction.y;
        aircraft->hitbox_rect.left += aircraft->direction.x;
        aircraft->hitbox_rect.top += aircraft->direction.y;
    }
}
