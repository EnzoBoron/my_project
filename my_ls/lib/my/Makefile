##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Make
##

SRC    =    	my_putchar.c				\
				cmp_word.c					\
				my_compute_power_rec.c		\
				my_compute_square_root.c	\
				my_find_prime_sup.c			\
				my_getnbr.c					\
				my_isneg.c					\
				my_is_prime.c				\
				my_put_nbr.c				\
				my_putstr.c					\
				my_revstr.c					\
				my_showmem.c				\
				my_showstr.c				\
				my_sort_int_array.c			\
				my_strcapitalize.c			\
				my_strcat.c					\
				my_strcmp.c					\
				my_str_isalpha.c			\
				my_str_islower.c			\
				my_str_isnum.c				\
				my_str_isprintable.c		\
				my_str_isupper.c			\
				my_strlen.c					\
				my_strlowcase.c				\
				my_strncat.c				\
				my_strncmp.c				\
				my_strncpy.c				\
				my_strstr.c					\
				my_strupcase.c				\
				my_swap.c					\
				my_put_nbr_print.c			\
				my_positive_nbr_print.c		\
				my_putchar_print.c			\
				my_putstr_print.c			\
				my_str_isnum_print.c		\
				my_octet_print.c			\
				my_put_usigned_print.c		\
				my_hex_upper_print.c		\
				my_hex_lower_print.c		\
				my_double_print.c			\
				my_adress_memory_print.c 	\
				my_binary_print.c			\
				my_pourcentage_n.c			\
				my_hex_lower_print_hash.c	\
				my_hex_upper_print_hash.c	\
				my_octet_print_hash.c		\
				my_ls_a.c					\
				my_ls_l.c					\
				my_ls_r_maj.c				\
				ls_r.c 						\
				ls_no_arg.c					\
				nothing.c					\
				my_str_remove.c


OBJ	=    $(SRC:.c=.o)

NAME	=	libmy.a

LIB	=	my.h

INCLUDE 	= 	cp $(LIB) ../../include

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
