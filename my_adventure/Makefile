##
## ENZO THOMMAS, 2022
## my_adventure
## File description:
## Makefile
##

SRC		=		main.c				\
				texture_entrer.c	\
				move.c				\
				create.c			\
				color.c				\
				my_gain.c 			\
				display.c 			\
				my_maps.c 			\

LIB		=		-L lib/my -lmy

NAME	=		my_adventure

MR	=	$(shell find ./ -name "#*#" -delete -o -name "*~" -delete)

all:
	make -C lib/my
	gcc $(SRC) $(LIB) -o $(NAME) -lncurses
	$(MR)

debug:
	make -C lib/my
	gcc $(SRC) $(LIB) -o $(NAME) -g -lncurses
	$(MR)

flag:
	make -C lib/my
	gcc $(SRC) $(LIB) -o $(NAME) -Wall -Wextra -W -lncurses
	$(MR)

clean:
	rm -f *.o
	$(MR)

fclean:	clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all
