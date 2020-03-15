##
## EPITECH PROJECT, 2020
## bitmap
## File description:
## Makefile
##

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"
WARNING				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\x1b[0m"
ERROR				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\x1b[0m"
DONE				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"

.PHONY				: all clean fclean re

LIB 				= libcsfml.a

SRC 				=	create_text_from_file.c	\
						create_text.c	\
						create_rect_shape.c	\
						create_sprite.c	\
						openf.c	\
						file_exist.c	\
						init_create.c	\
						open_free.c	\
						rect_mouse_hovering.c	\
						createf/createf.c	\
						createf/createf_ext.c	\
						createf/createf_event.c	\
						createf/createf_draw.c	\
						createf/createf_init.c	\
						createf/check_validity_input.c	\

CFLAGS 				= -Wall -I./include

MV					= mv

CP					= cp -rf

AR 					= @ar rc

INCLUDE 			= ./include

INCLUDE_FOLDER		= include/

REMOTE_INCLUDE 		= ../../include/library/csfml

LIB_OBJ 			= $(SRC:.c=.o)

all:				$(LIB)
					@$(MV) $(LIB) ../$(LIB)
					@$(CP) $(wildcard include/*.h) $(REMOTE_INCLUDE)
					@$(call SUCCESS, "[ OK ] libcsfml library has been copied.")
					@$(call DONE, "[ DONE 100% ]")

$(LIB):			$(LIB_OBJ)
					@$(AR) $(LIB) $(LIB_OBJ)
					@$(call SUCCESS, "[ OK ] libcsfml library successfully compiled.")

clean_lib:
					@$(RM) $(LIB)
					@$(RM) ../$(LIB)

clean:
					@$(RM) $(LIB_OBJ)
					@$(call SUCCESS, "[ OK ] *.o are removed in libbitlibcsfml")

fclean: 			clean
					@$(RM) ../$(LIB)
					@$(call SUCCESS, "[ OK ] libcsfml library fully cleaned.")

re: 				fclean all