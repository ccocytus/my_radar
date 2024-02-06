/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** prototypes.c
*/

#ifndef MY_PROTOTYPES_H_
        #define MY_PROTOTYPES_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>

    typedef struct aircraft {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *hitbox;
    sfColor hitbox_color;
    float hitbox_thickness;
    sfVector2f hitbox_position;
    sfVector2f hitbox_size;
    sfIntRect hitbox_rect;
    sfVector2f departure;
    sfVector2f direction;
    sfVector2f position;
    sfVector2f arrival;
    int position_case;
    int rotation;
    int speed;
    int delay;
    int decollage;
    int nb_towers;
    int aterri;
    int destroyed;
} aircraft_t;

typedef struct tower {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfCircleShape *area;
    sfColor area_color;
    float area_thickness;
    sfVector2f area_position;
    int radius;
} tower_t;

typedef struct grid_base {
    sfRectangleShape *rectangle;
    sfColor fill_color;
    sfColor outline_color;
    float outline_thickness;
    sfVector2f size;
    sfVector2f position;
} grid_base_t;

typedef struct the_timer {
    int sec;
    int minutes;
} the_timer_t;

typedef struct game {
    aircraft_t **aircrafts;
    tower_t **towers;
    grid_base_t **grid;
    the_timer_t *the_timer;
    sfSprite *map_sprite;
    sfTexture *map_texture;
    sfSprite *menu_sprite;
    sfTexture *menu_texture;
    sfClock *global;
    sfClock *movement;
    sfClock *fps_clock;
    int nb_t;
    int nb_a;
    int landed;
    int destroyed;
    int start;
    int end;
    int fps;
    int key_l;
    int key_s;
    int key_f;
    int key_g;
    int key_t;
} game_t;

char *my_strappend(char *str, char src);
int my_getnbr(char const *str);
char *my_int_to_str(int nb);
int rev(int nb);
int nbsize(int nb);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);

int position_case(sfVector2f departure, sfVector2f arrival);
sfRectangleShape *hitbox_aircraft(aircraft_t *aircraft);
sfSprite *sprite_aircraft(aircraft_t *aircraft);
void set_aircraft(aircraft_t *aircraft, game_t *game);
void seetting_aircraft(game_t *game, char *line);
sfVector2f way_head(aircraft_t *aircraft);
int rotation(aircraft_t *aircraft);
int nb_aircrafts(FILE *file, char *lines, size_t size);
char *add_to_tab(char *line, int i);
char **parser(char *line);
int read_file(game_t *game, FILE *file, char *lines, size_t size);
void check_two(game_t *game, char *line, size_t len, char *filepath);
game_t *check_file(char *filepath);
sfSprite *map_sprite(game_t *game);
void set_map_sprite(game_t *game);
sfSprite *menu_sprite(game_t *game);
void the_menu(game_t *game);
void menu(sfRenderWindow *win, game_t *game, sfEvent event);
sfCircleShape *tower_area(tower_t *tower);
sfSprite *tower_sprite(tower_t *tower);
void setting_tower(game_t *game, char *line);
int towers_i_file(FILE *file, char *lines, size_t size);

void destroy_aircrafts(game_t *game, aircraft_t *aircraft_a,
    aircraft_t *aircraft_b);
void aircraft_collision(game_t *game, aircraft_t *aircraft, int i);
void render_hitboxes_aircrafts(game_t *game, sfRenderWindow *win,
    aircraft_t *aircraft);
void set_hitboxes_aircrafts(aircraft_t *aircraft);
int collision_top_left(game_t *game, aircraft_t *aircraft, int i);
int collision_top_right(game_t *game, aircraft_t *aircraft, int i);
int collision_bottom_left(game_t *game, aircraft_t *aircraft, int i);
int collision_bottom_right(game_t *game, aircraft_t *aircraft, int i);
void in_tower_area(game_t *game, aircraft_t *aircraft);
void start_end(game_t *game, aircraft_t *aircraft);
int check_landing(aircraft_t *aircraft);
void aircrafts_move(game_t *game, aircraft_t *aircraft);
void render_aircrafts(game_t *game, sfRenderWindow *win,
    aircraft_t *aircraft);
void draw_aircrafts(sfRenderWindow *win, game_t *game);
void destroy_game(game_t *game, sfRenderWindow *win);
void free_game(game_t *game);
void close_window(sfRenderWindow *win);
void manage_keys(game_t *game, sfRenderWindow *win, sfKeyCode code);
void analyse_events(sfRenderWindow *win, game_t *game, sfEvent event);
void show_fps(sfRenderWindow *win, game_t *game);
void get_fps(sfRenderWindow *win, game_t *gam);
void start_game(sfRenderWindow *win, game_t *game, float sec);
void game_steps(game_t *game, sfRenderWindow *win, float sec,
    sfEvent event);
void game_loop(sfRenderWindow *win, game_t *game, sfEvent event);
int display_usage(void);
int good_arguments(int ac, char **av);
int bad_arguments(void);
int main(int ac, char **av);
void display_grid(sfRenderWindow *win, game_t *game);
void prin_grid(game_t *game, int i);
void grid(game_t *game);
void set_minutes_print(sfRenderWindow *win, game_t *game, sfText *text);
void set_secprint(sfRenderWindow *win, game_t *game, sfText *text);
void print_timer(sfRenderWindow *win, game_t *game);
void get_timer(sfRenderWindow *win, game_t *game);
void area_towers(sfRenderWindow *win, game_t *game, int i);
void draw_towers(sfRenderWindow *win, game_t *game, int j);
void print_towers(sfRenderWindow *win, game_t *game);
int get_result(int position_case, sfVector2f position, sfVector2f arrival);
int check_case_1(sfVector2f position, sfVector2f arrival);
int check_case_2(sfVector2f position, sfVector2f arrival);
int check_case_3(sfVector2f position, sfVector2f arrival);
int check_case_4(sfVector2f position, sfVector2f arrival);
int check_case_5(sfVector2f position, sfVector2f arrival);
int check_case_6(sfVector2f position, sfVector2f arrival);
int check_case_8(sfVector2f position, sfVector2f arrival);
int check_case_7(sfVector2f position, sfVector2f arrival);

    #define MIN(a, b)            (((a) < (b)) ? (a) : (b))
    #define MAX(a, b)            (((a) > (b)) ? (a) : (b))
    #define MAX_WINDOW          MAX(1920, 1080)
    #define RADIUS(x)           ((x) * 1920 / 1400)

#endif /* !MY_PROTOTYPES_H_ */
