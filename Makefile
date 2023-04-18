##
## EPITECH PROJECT, 2023
## MyRPG
## File description:
## Makefile
##

CC ?=	gcc
SRC = 	source/display/window.c \
		source/map/initalise.c \
		source/map/draw.c \
		source/sprites/initialise.c \
		source/map/free_map.c \
		source/movements/check_move.c\
		source/movements/horizontal_move.c\
		source/movements/vertical_move.c\
		source/player/draw_player.c\
		source/player/init_player.c\

OBJ = $(SRC:.c=.o)

MAIN = source/main.c

NAME = my_rpg

EXEC = ./$(NAME)

VALGRIND_PARAMS ?= '-h'

CFLAGS = -Wall -Wextra
CPPFLAGS = -iquote include
LDFLAGS = -L/lib -lmy -lcsfml-graphics -lcsfml-window \
		  -lcsfml-system -lcsfml-audio

LIB 	=	-lmy

DIR	=	-L./lib/

MKDIR = mkdir -p

all: $(NAME)


$(NAME): 	SRC += $(MAIN)
$(NAME): 	$(OBJ) $(MAIN:.c=.o)
			$(MAKE) -C ./lib/my
			$(CC) $(OBJ) -o $(NAME) $(DIR) $(LIB) $(LDFLAGS) $(CFLAGS)

clean:
		$(RM) $(OBJ) $(MAIN:.c=.o)
		$(MAKE) clean -C ./lib/my

fclean: clean
		$(RM) $(NAME) vgcore*
		$(MAKE) fclean -C ./lib/my

re: fclean
	$(MAKE) all

debug: CFLAGS += -g
debug: re

valgrind: 	re
			valgrind $(EXEC) $(VALGRIND_PARAMS)

.PHONY: all lib clean fclean re valgrind
