##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	show_list.c	\
		create_node.c	\
		fill_list.c	\
		list_length.c	\
		insert_node_end.c	\
		insert_node_index.c	\
		remove_node_index.c	\
		remove_node_begin.c	\
		remove_node_end.c	\
		get_node_index.c

OBJ	=	$(SRC:.c=.o)

NAME	=	liblinked_list.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp lib_linked_list.h ./../../include/lib/
	cp $(NAME) ./../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./../$(NAME)

re: fclean all