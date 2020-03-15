##
## EPITECH PROJECT, 2020
## PSU_my_printf_2019
## File description:
## Makefile
##

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"
WARNING				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\x1b[0m"
ERROR				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\x1b[0m"
DONE				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"

.PHONY				: all clean fclean re

LIB 				= libmy_printf.a

SRC 				=	$(wildcard *.c)

CFLAGS 				= -Wall -I./include

CC					= @gcc

AR 					= @ar rc

CP 					= cp

RM 					= rm -f

INCLUDE 			= ./include

REMOTE_INCLUDE 		= ../../include/main/my_printf/

INCLUDE_FILE		= my_printf.h

LIB_OBJ 			= $(SRC:.c=.o)

all:				$(LIB) clean
					@$(CP) $(LIB) ../$(LIB)
					@$(CP) $(INCLUDE)/$(INCLUDE_FILE) $(REMOTE_INCLUDE)
					@$(call SUCCESS, "[ OK ] Libmy_printf library has been copied.")
					@$(call DONE, "[ DONE 100% ]")

$(LIB):			$(LIB_OBJ)
					@$(AR) $(LIB) $(LIB_OBJ)
					@$(call SUCCESS, "[ OK ] Libmy_printf library successfully compiled.")

clean_lib:
					@$(RM) $(LIB)
					@$(RM) ../$(LIB)

clean:
					@$(RM) $(LIB_OBJ)
					@$(call SUCCESS, "[ OK ] *.o are removed in libmy_printf_printf")

fclean: 			clean
					@$(RM) ../$(LIB)
					@$(RM) $(LIB)
					@$(RM) $(REMOTE_INCLUDE)$(INCLUDE_FILE)
					@$(call SUCCESS, "[ OK ] Libmy_printf library fully cleaned.")

re: 				fclean all