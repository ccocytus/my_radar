/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** menu.c
*/
#include "../include/my_prototypes.h"

sfSprite *menu_sprite(game_t *game)
{
    sfSprite *sprite = sfSprite_create();

    game->menu_texture = sfTexture_createFromFile("images/map_blur.png", NULL);
    sfSprite_setTexture(sprite, game->menu_texture, sfTrue);
    return (sprite);
}

void the_menu(game_t *game)
{
    game->menu_sprite = menu_sprite(game);
}

void menu(sfRenderWindow *win, game_t *game, sfEvent event)
{
    sfFont *font = sfFont_createFromFile("fonts/Horison.ttf");
    sfVector2f position = {500, 450};
    sfText *text = sfText_create();

    sfText_setString(text,
    "Press any button to start the game");
    sfText_setFont(text, font);
    sfText_setPosition(text, position);
    sfText_setCharacterSize(text, 60);
    sfText_setFillColor(text, sfGreen);
    sfRenderWindow_drawSprite(win, game->menu_sprite, NULL);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfClock_restart(game->global);
}
