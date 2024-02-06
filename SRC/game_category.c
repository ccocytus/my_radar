/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** game category
*/

#include "../include/my_prototypes.h"

void start_game(sfRenderWindow *win, game_t *game, float sec)
{
    if (sec > 0.005) {
        sfClock_restart(game->movement);
        sfRenderWindow_drawSprite(win, game->map_sprite, NULL);
        print_towers(win, game);
        draw_aircrafts(win, game);
        get_fps(win, game);
        get_timer(win, game);
        display_grid(win, game);
        if (game->key_f == 1)
            show_fps(win, game);
        if (game->key_t == 1)
            print_timer(win, game);
    }
}

void game_steps(game_t *game, sfRenderWindow *win, float sec,
    sfEvent event)
{
    if (game->start == 1)
        start_game(win, game, sec);
    else
        menu(win, game, event);
    if (game->end == 1)
        close_window(win);
}

void game_loop(sfRenderWindow *win, game_t *game, sfEvent event)
{
    sfTime time;
    float sec = 1.0;
    sfVector2i window_pos = {0, 0};

    sfRenderWindow_setPosition(win, window_pos);
    sfRenderWindow_setFramerateLimit(win, 60);
    game->global = sfClock_create();
    game->the_timer->minutes = 0;
    game->the_timer->sec = 0;
    while (sfRenderWindow_isOpen(win)) {
        analyse_events(win, game, event);
        sec = time.microseconds / 1000000.0;
        time = sfClock_getElapsedTime(game->movement);
        game_steps(game, win, sec, event);
        sfRenderWindow_display(win);
        sfRenderWindow_clear(win, sfBlack);
    }
}

void free_game(game_t *game)
{
    for (int i = 0; i < game->nb_t; i++)
        free(game->towers[i]);
    free(game->towers);
    for (int i = 0; i < game->nb_a; i++)
        free(game->aircrafts[i]);
    free(game->aircrafts);
    for (int i = 0; i < 100; i++)
        free(game->grid[i]);
    free(game->grid);
    free(game->the_timer);
    free(game);
}

void destroy_game(game_t *game, sfRenderWindow *win)
{
    for (int i = 0; i < game->nb_a; i++) {
        sfTexture_destroy(game->aircrafts[i]->texture);
        sfSprite_destroy(game->aircrafts[i]->sprite);
        sfRectangleShape_destroy(game->aircrafts[i]->hitbox);
    }
    for (int i = 0; i < game->nb_t; i++) {
        sfTexture_destroy(game->towers[i]->texture);
        sfSprite_destroy(game->towers[i]->sprite);
        sfCircleShape_destroy(game->towers[i]->area);
    }
    for (int i = 0; i < 100; i++)
        sfRectangleShape_destroy(game->grid[i]->rectangle);
    sfTexture_destroy(game->map_texture);
    sfSprite_destroy(game->map_sprite);
    sfTexture_destroy(game->menu_texture);
    sfSprite_destroy(game->menu_sprite);
    sfClock_destroy(game->global);
    sfClock_destroy(game->movement);
    sfClock_destroy(game->fps_clock);
    sfRenderWindow_destroy(win);
}
