##
## EPITECH PROJECT, 2022
## my_ctype
## File description:
## Makefile
##

SRC		=		is_alnum.c		\
				is_alpha.c		\
				is_cntrl.c		\
				is_digit.c		\
				is_graph.c		\
				is_lower.c		\
				is_print.c		\
				is_punct.c		\
				is_space.c		\
				is_upper.c		\
				is_xdigit.c		\
				to_lower.c		\
				to_upper.c		\
				my_bsq.c

OBJ			=    $(SRC:.c=.o)

NAME		=	libmy_ctype.a

LIB			=	my_ctype.h

INCLUDE 	= 	cp $(LIB) ../../include

CP 			=	 cp $(NAME) ../../

MR			=	$(shell find ./ -name "#*#" -delete -o -name "*~" -delete)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	$(CP)
	$(INCLUDE)
	$(MR)

clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)
	rm -f ../../$(NAME);

re:	fclean all
