##
## EPITECH PROJECT, 2022
## my_string
## File description:
## Makefile
##

SRC			=	my_strcat.c 	\
				my_strcmp.c		\
				my_strcpy.c		\
				my_strchr.c		\
				my_strlen.c

OBJ			=    $(SRC:.c=.o)

NAME		=	libmy_string.a

LIB			=	my_string.h

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
