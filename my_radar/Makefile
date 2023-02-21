##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Make
##

SRC   	=	src/main.c 					\
			src/create_env_csfml.c		\
			src/loop_game.c				\
			src/file.c					\
			src/deplacement_direction.c	\
			src/collision_plane.c 		\

NAME	=	my_radar

LIB		=	-L include -L lib/my -lmy

CSFML	=	-lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system

MR	=	$(shell find ./ -name "#*#" -delete -o -name "*~" -delete)

all:
	make -C lib/my
	gcc $(SRC) $(LIB) $(CSFML) -o $(NAME)
	$(MR)

flag:
	make -C lib/my
	gcc $(SRC) $(LIB) $(CSFML) -W -Wall -Wextra -o $(NAME)
	$(MR)

debug:
	make -C lib/my
	gcc $(SRC) $(LIB) $(CSFML) -g -o $(NAME)
	$(MR)

clean:
	rm -f $(NAME)

fclean: clean
	make fclean -C lib/my
	rm -f coding-style-repport.log
	rm -f *.a

re:	fclean all
	make re -C lib/my
