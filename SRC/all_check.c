/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** aircraft_category.c
*/

#include "../include/my_prototypes.h"

int read_file(game_t *game, FILE *file, char *lines, size_t size)
{
    while (getline(&lines, &size, file) != -1) {
        if (lines[0] != 'A' && lines[0] != 'T') {
            my_putstr("Error : the file is not a script\n");
            return (1);
        }
        if (lines[0] == 'A')
            seetting_aircraft(game, lines);
        if (lines[0] == 'T')
            setting_tower(game, lines);
    }
    if (lines)
        free(lines);
}

void check_two(game_t *game, char *li, size_t len, char *filepath)
{
    FILE *fp = fopen(filepath, "r");

    game->aircrafts = malloc(sizeof(aircraft_t) *
    (nb_aircrafts(fp, li, len) + 1));
    fp = fopen(filepath, "r");
    game->towers = malloc(sizeof(tower_t) * (towers_i_file(fp, li, len) + 1));
    game->grid = malloc(sizeof(grid_base_t) * 100);
    game->the_timer = malloc(sizeof(the_timer_t));
    game->nb_a = 0;
    game->nb_t = 0;
    game->start = 0;
    game->end = 0;
    game->fps = 0;
    game->key_l = 0;
    game->key_s = 1;
    game->key_f = 0;
    game->key_g = 0;
    game->key_t = 1;
}

game_t *check_file(char *filepath)
{
    game_t *game = malloc(sizeof(game_t));
    FILE *file = fopen(filepath, "r");
    char *ligne = NULL;
    size_t size = 0;

    if (file == NULL) {
        my_putstr("Error : file doesn't exist\n");
        return (NULL);
    }
    check_two(game, ligne, size, filepath);
    file = fopen(filepath, "r");
    if (read_file(game, file, ligne, size) == 1)
        return (NULL);
    the_menu(game);
    set_map_sprite(game);
    grid(game);
    return (game);
}

char **parser(char *line)
{
    char **information = malloc(sizeof(char *) * my_strlen(line));
    int i = 1;
    int j = 0;

    while (line[i] != '\0') {
        if (line[i - 1] == ' ' && line[i] != ' ') {
            information[j] = add_to_tab(line, i);
            j++;
        }
        i++;
    }
    return (information);
}
