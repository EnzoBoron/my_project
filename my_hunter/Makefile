##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Make
##

SRC   	=	my_hunter.c				\
			display_create.c 		\
			option.c 				\
			gameplay.c				\
			placement_direction.c	\
			destoy.c				\
			init_sprite.c			\
			gameplay_medium.c		\
			direction.c				\
			gameplay_hard.c

NAME	=	my_hunter

LIB		=	-L include -L lib/my -lmy

#CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
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
