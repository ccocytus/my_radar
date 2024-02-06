/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** events
*/

#include "../include/my_prototypes.h"

void manage_keys(game_t *game, sfRenderWindow *win, sfKeyCode code)
{
    if (code == sfKeyS)
        game->key_s = game->key_s == 1 ? 0 : 1;
    if (code == sfKeyL)
        game->key_l = game->key_l == 1 ? 0 : 1;
    if (code == sfKeyF)
        game->key_f = game->key_f == 1 ? 0 : 1;
    if (code == sfKeyG)
        game->key_g = game->key_g == 1 ? 0 : 1;
    if (code == sfKeyT)
        game->key_t = game->key_t == 1 ? 0 : 1;
    if (code == sfKeyQ)
        close_window(win);
}

void analyse_events(sfRenderWindow *win, game_t *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(win, &event)) {
        if ((event.type == sfEvtMouseButtonPressed ||
        event.type == sfEvtKeyPressed && event.key.code != sfKeyQ)
        && game->start == 0) {
            game->start = 1;
            break;
        }
        if (event.type == sfEvtClosed)
            close_window(win);
        if (event.type == sfEvtKeyPressed)
            manage_keys(game, win, event.key.code);
    }
}

void close_window(sfRenderWindow *win)
{
    sfRenderWindow_close(win);
}
