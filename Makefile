##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_ls
##

SRC =	my_radar.c	\
		SRC/menu_category.c	\
		SRC/map_category.c	\
		SRC/aircraft_category.c	\
		SRC/all_collision.c	\
		SRC/aircraft_settings.c	\
		SRC/all_check.c	\
		SRC/tower_category.c	\
		SRC/display_towers.c	\
		SRC/game_category.c	\
		SRC/aircraft_setting2.c	\
		SRC/fps_category.c	\
		SRC/timer_category.c	\
		SRC/grid_category.c	\
		SRC/events_category.c	\
		SRC/position_check.c	\
		SRC/position_check2.c	\

OBJ = $(SRC:.c=.o)

NAME = my_radar

CFLAGS = -I./include

LDFLAGS = -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	gcc $(OBJ) -o $(NAME) $(LDFLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a

re: fclean all
