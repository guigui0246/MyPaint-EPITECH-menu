##
## EPITECH PROJECT, 2022
## My Paint
## File description:
## Make file for paint
##

CC ?= gcc

SRC =	main.c \
		window.c \
		event.c \
		window_clean.c \
		button/button.c \
		button/lock.c \
		button/event.c \
		button/create.c \
		button/text.c \
		menu/menu.c \
		menu/lock.c \
		menu/open.c \
		menu/create.c \
		menu/destroy.c \
		menu/click.c \
		menu/add_elem.c \
		effect.c \
		paint.c \
		load.c \
		button_effect/save.c \
		button_effect/load.c \
		button_effect/color.c \
		button_effect/help.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra

INCLUDE_DIR = ./include

CPPFLAGS += $(foreach inc, $(INCLUDE_DIR), -I$(inc))

LIB = my \
		csfml-graphics \
		csfml-window \
		csfml-system

LIB_DIR = ./lib

LIB_TO_MAKE = ./lib/my

LDFLAGS += $(foreach lib, $(LIB_DIR), -L$(lib))
LDLIBS += $(foreach lib, $(LIB), -l$(lib))

NAME = my_paint

all: $(NAME)

make_lib:
	make -i -C $(LIB_TO_MAKE)

$(NAME): make_lib $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	make clean -i -C $(LIB_TO_MAKE)
	rm -f $(OBJ)

fclean: clean
	make fclean -i -C $(LIB_TO_MAKE)
	rm -f $(NAME)

re: fclean all

help:
	make my_radar
	./my_radar -h

.PHONY	: clean fclean re all make_lib help
