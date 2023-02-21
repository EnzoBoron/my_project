##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Make
##

SRC   	=	squar.c

NAME	=	my_circle

LIB		=	-L include -L lib/my -lmy

CSFML	=	-lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system

MR	=	$(shell find ./ -name "#*#" -delete -o -name "*~" -delete)

EXE 	= 	-o $(NAME).exe

all:
	gcc $(SRC) $(CSFML) -o $(NAME)
	$(MR)

flag:
	gcc $(SRC) $(CSFML) -W -Wall -Wextra -o $(NAME)
	$(MR)

pexe:
	 gcc -fPIC -c squar.c
	gcc -shared -o squar.so squar.o

debug:
	gcc $(SRC) $(CSFML) -g -o $(NAME)
	$(MR)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f coding-style-repport.log
	rm -f *.a

re:	fclean all
