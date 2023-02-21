##
## EPITECH PROJECT, 2022
## B-CPE-110-LIL-1-1-BSQ-enzo.boron
## File description:
## Makefile
##

SRC				=	bsq.c	\
					my_str_to_world_array_bsq.c \
					opening_file.c	\
					convect_in_number.c


NAME 			=	bsq

STRING			=	-L lib/my_string -lmy_string

CTYPE			=	-L lib/my_ctype -lmy_ctype

MY				=	-L lib/my -lmy

INCLUDE			=	-L include/

LIB_FILE 	=	-L lib/file_info -lmy_file

MAKE 		=	make -C lib/my && make -C lib/my_ctype && make -C lib/my_string

MAKERE		=	make re -C lib/my && make re -C lib/my_ctype

MAKEFCLEAN	=	make fclean -C lib/my && make fclean -C lib/my_ctype

MAKE_STRING_CLEAN	=	make fclean -C lib/my_string

MAKE_STRING_RE		=	make re -C lib/my_string

RM_CODI			=	rm -f coding-style-reports.log

MAKE_INFO_FILE	=	make -C lib/file_info

RE_INFO_FILE	=	make re -C lib/file_info

CLEAN_INFO_FILE	=	make fclean -C lib/file_info

all:
	$(MAKE)
	gcc $(SRC) $(INCLUDE) $(MY) $(CTYPE) $(STRING) -W -Wall -Wextra -o $(NAME)

debug:
	$(MAKE)
	gcc -g $(SRC) $(INCLUDE) $(MY) $(CTYPE) $(STRING) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	$(MAKEFCLEAN)
	$(MAKE_STRING_CLEAN)
	$(RM_CODI)

re: fclean all
	$(MAKERE)
	$(MAKE_STRING_RE)
