/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** display_towers.c
*/

#include "../include/my_prototypes.h"

void draw_towers(sfRenderWindow *win, game_t *game, int j)
{
    sfRenderWindow_drawSprite(win, game->towers[j]->sprite, NULL);
}

sfSprite *tower_sprite(tower_t *tower)
{
    sfSprite *sprite = sfSprite_create();

    tower->texture =
    sfTexture_createFromFile("images/tower.png", NULL);
    sfSprite_setTexture(sprite, tower->texture,
    sfTrue);
    return (sprite);
}

void print_towers(sfRenderWindow *win, game_t *game)
{
    tower_t **towers = game->towers;
    int i = 0;

    while (i < game->nb_t) {
        sfSprite_setPosition(towers[i]->sprite, towers[i]->position);
        sfCircleShape_setOrigin(game->towers[i]->area, (sfVector2f)
        {RADIUS(towers[i]->radius), RADIUS(towers[i]->radius)});
        sfCircleShape_setPosition(towers[i]->area, towers[i]->area_position);
        sfCircleShape_setRadius(towers[i]->area, RADIUS(towers[i]->radius));
        sfCircleShape_setFillColor(towers[i]->area, sfTransparent);
        sfCircleShape_setOutlineColor(towers[i]->area, towers[i]->area_color);
        sfCircleShape_setOutlineThickness(towers[i]->area,
        towers[i]->area_thickness);
        if (game->key_s == 1)
            draw_towers(win, game, i);
        if (game->key_l == 1)
            area_towers(win, game, i);
        i++;
    }
}
