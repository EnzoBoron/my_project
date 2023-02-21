##
## EPITECH PROJECT, 2020
## 102architect
## File description:
## Makefile
##

SRC			:= 103cipher.py

NAME		=	103cipher
MAKEFLAGS 	+=	--no-print-directory

.PHONY:		all
all:		$(NAME)
$(NAME):
			cp $(SRC) $(NAME)
			chmod +x $(NAME)

.PHONY:		tests_run

.PHONY:		clean
clean:
			$(RM) -rf src/__pycache__ test/__pycache__ .coverage

.PHONY:		fclean
fclean:		clean
			$(RM) $(NAME)

.PHONY:		re
re:			fclean all