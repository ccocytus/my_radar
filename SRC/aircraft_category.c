/*
** EPITECH PROJECT, 2024
** all_collision.c
** File description:
** my_radar
*/

#include "../include/my_prototypes.h"

void set_aircraft(aircraft_t *aircraft, game_t *game)
{
    sfSprite_setOrigin(aircraft->sprite,
    (sfVector2f) {20 / 2, 20 / 2});
    sfSprite_setRotation(aircraft->sprite, aircraft->rotation);
    aircraft->decollage = 0;
    aircraft->aterri = 0;
    aircraft->nb_towers = 0;
    aircraft->destroyed = 0;
    game->landed = 0;
    game->destroyed = 0;
}

sfSprite *sprite_aircraft(aircraft_t *aircraft)
{
    sfSprite *sprite = sfSprite_create();

    aircraft->texture = sfTexture_createFromFile("images/plane.png", NULL);
    sfSprite_setTexture(sprite, aircraft->texture, sfTrue);
    sfSprite_setPosition(sprite, aircraft->departure);
    return (sprite);
}

void draw_aircrafts(sfRenderWindow *win, game_t *game)
{
    aircraft_t **aircrafts = game->aircrafts;

    game->landed = 0;
    for (int i = 0; i < game->nb_a; i++) {
        start_end(game, aircrafts[i]);
        game->landed += aircrafts[i]->aterri;
        in_tower_area(game, aircrafts[i]);
        if (aircrafts[i]->destroyed == 0 && aircrafts[i]->nb_towers == 0)
            aircraft_collision(game, aircrafts[i], i);
        set_hitboxes_aircrafts(aircrafts[i]);
        aircrafts_move(game, aircrafts[i]);
        if (game->key_s)
            render_aircrafts(game, win, aircrafts[i]);
        if (game->key_l)
            render_hitboxes_aircrafts(game, win, aircrafts[i]);
    }
    if (game->nb_a == game->destroyed + game->landed)
        game->end = 1;
}

void destroy_aircrafts(game_t *game, aircraft_t *aircraft_a,
    aircraft_t *aircraft_b)
{
    if (sfIntRect_intersects(&aircraft_a->hitbox_rect,
    &aircraft_b->hitbox_rect, NULL)) {
        aircraft_a->destroyed = 1;
        aircraft_b->destroyed = 1;
        game->destroyed += 2;
    }
}

void start_end(game_t *game, aircraft_t *aircraft)
{
    float time = sfClock_getElapsedTime(game->global).microseconds / 1000000.0;

    if (time >= aircraft->delay)
        aircraft->decollage = 1;
    if (check_landing(aircraft) != 0)
        aircraft->aterri = 1;
}
