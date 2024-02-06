/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** fps
*/

#include "../include/my_prototypes.h"

void show_fps(sfRenderWindow *window, game_t *game)
{
    sfFont *font = sfFont_createFromFile("fonts/digital.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfGreen);
    sfText_setString(text, my_int_to_str(game->fps));
    sfText_setPosition(text, (sfVector2f) {990, 1000});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_setString(text, "FPS : ");
    sfText_setPosition(text, (sfVector2f) {930, 1000});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void get_fps(sfRenderWindow *win, game_t *gam)
{
    static int first = 1;
    static int fps = 0;

    if (first == 1) {
        gam->fps_clock = sfClock_create();
        first = 0;
    }
    if (sfClock_getElapsedTime(gam->fps_clock).microseconds / 1000000.0 >= 1) {
        gam->fps = fps;
        fps = 0;
        sfClock_restart(gam->fps_clock);
    } else
        fps++;
}
