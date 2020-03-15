##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC 	=	my_atoi.c			\
			my_swap.c			\
			my_cpy.c			\
			my_putchar.c		\
			my_put_nbr.c		\
			my_putstr.c			\
			my_revstr.c			\
			my_strlen.c			\
			my_strcat.c			\
			my_intchar.c		\
			my_strcmp.c			\
			my_isalpha_num.c	\
			my_occur.c			\
			my_intlen.c			\
			my_free.c			\
			my_malloc.c			\
			my_getline.c		\
			support_getline.c	\
			my_clean.c			\
			my_base.c

OBJ 	=	$(SRC:.c=.o)

NAME 	= 	libjmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ./../../include/lib/
	cp color.h ./../../include/lib/
	cp my_getline.h ./../../include/lib/
	mv $(NAME) ./../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./../$(NAME)

re: fclean all