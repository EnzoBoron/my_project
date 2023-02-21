##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Make
##

SRC    =    	file_info.c


OBJ	=    $(SRC:.c=.o)

NAME	=	libmy_file.a

LIB	=	my_file.h

INCLUDE 	= 	cp $(NAME) ../../include

CP 	=	 cp $(NAME) ../../

MR	=	$(shell find ./ -name "#*#" -delete -o -name "*~" -delete)

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
