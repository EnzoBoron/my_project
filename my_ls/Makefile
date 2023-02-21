##
## EPITECH PROJECT, 2022
## B-PSU-100-LIL-1-1-myls-enzo.boron
## File description:
## Makefile
##

CC 			=		gcc

SRC 		=		my_ls.c

NAME		=		my_ls

LIB			=		-L include -L lib/my -lmy -o

MAKE_MY		=		make -C lib/my

all:
	$(MAKE_MY)
	$(CC) $(SRC) $(LIB) $(NAME)

flag:
	$(MAKE_MY)
	$(CC) $(SRC) $(LIB) $(NAME) -Wall -W -Wextra

debug:
	$(MAKE_MY)
	$(CC) $(SRC) $(LIB) $(NAME) -g

clean:
	rm -f $(NAME)

fclean: clean
	make fclean -C lib/my
	rm -f coding-style-reports.log

re: all
