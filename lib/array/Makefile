##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

SRC 	=	my_otoo.c	\
			my_ooto.c	\
			my_ootooo.c	\
			my_oootoo.c	\
			my_putc.c	\
			my_puto.c	\
			my_putoo.c	\
			my_putooo.c	\
			my_length_o.c		\
			my_length_oo.c		\
			my_length_ooo.c		\
			my_add_o_too.c		\
			my_add_oo_tooo.c	\
			my_free_oo.c		\
			my_free_typoo.c		\
			my_free_ooo.c		\
			my_rm_o_too.c		\
			my_cpy_o.c			\
			my_cpy_oo.c			\
			my_count.c

OBJ 	=	$(SRC:.c=.o)

NAME 	= 	libarray.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp array.h ./../../include/lib/
	cp $(NAME) ./../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./../$(NAME)

re: fclean all