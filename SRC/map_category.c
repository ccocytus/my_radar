/*
** EPITECH PROJECT, 2024
** Epitech
** File description:
** map
*/

#include "../include/my_prototypes.h"

sfSprite *map_sprite(game_t *game)
{
    sfSprite *sprite = sfSprite_create();

    game->map_texture = sfTexture_createFromFile("images/map.jpg", NULL);
    sfSprite_setTexture(sprite, game->map_texture, sfTrue);
    return (sprite);
}

void set_map_sprite(game_t *game)
{
    game->map_sprite = map_sprite(game);
}
