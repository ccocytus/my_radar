/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** timer.c
*/

#include "../include/my_prototypes.h"

void set_minutes_print(sfRenderWindow *win, game_t *game, sfText *text)
{
    if (game->the_timer->minutes < 10) {
        sfText_setString(text, "0");
        sfText_setPosition(text, (sfVector2f) {939, 10});
        sfRenderWindow_drawText(win, text, NULL);
    }
    sfText_setString(text, my_int_to_str(game->the_timer->minutes));
    if (game->the_timer->minutes >= 10)
        sfText_setPosition(text, (sfVector2f) {940, 10});
    else
        sfText_setPosition(text, (sfVector2f) {970, 10});
    sfRenderWindow_drawText(win, text, NULL);
}

void set_secprint(sfRenderWindow *win, game_t *game, sfText *text)
{
    if (game->the_timer->sec < 10) {
        sfText_setString(text, "0");
        sfText_setPosition(text, (sfVector2f) {1009, 10});
        sfRenderWindow_drawText(win, text, NULL);
    }
    sfText_setString(text, my_int_to_str(game->the_timer->sec));
    if (game->the_timer->sec >= 10)
        sfText_setPosition(text, (sfVector2f) {1010, 10});
    else
        sfText_setPosition(text, (sfVector2f) {1040, 10});
    sfRenderWindow_drawText(win, text, NULL);
}

void print_timer(sfRenderWindow *win, game_t *game)
{
    sfFont *font = sfFont_createFromFile("fonts/digital.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setFillColor(text, sfYellow);
    set_minutes_print(win, game, text);
    sfText_setString(text, ":");
    sfText_setPosition(text, (sfVector2f) {1000, 10});
    sfRenderWindow_drawText(win, text, NULL);
    set_secprint(win, game, text);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void get_timer(sfRenderWindow *win, game_t *game)
{
    sfTime elapsed = sfClock_getElapsedTime(game->global);

    game->the_timer->sec = elapsed.microseconds / 1000000;
    game->the_timer->minutes = game->the_timer->sec / 60;
    game->the_timer->sec = game->the_timer->sec % 60;
}
