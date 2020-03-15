##
## EPITECH PROJECT, 2020
## my_world_2019
## File description:
## Makefile
##

## ========================================================================== ##
PATH_DISP		=	template/infobar/source/display/
DISP			=	display_infobar.c


## ========================================================================== ##
PATH_INIT		=	template/infobar/source/init/
INIT			=	init_infobar.c	\
					init_section_hovering.c	\


## ========================================================================== ##
PATH_EVENT		=	template/infobar/event/
EVENT			=	event_hovering_nav.c	\
					event_click_nav.c	\


## ========================================================================== ##
PATH_SOURCE_EVENT	=	event/
SOURCE_EVENT		=	event_hovering_button.c	\
						poll_hovering_button.c	\


## ========================================================================== ##
PATH_SOURCE_INIT		=	source/init/
SOURCE_INIT				=	init_scene.c	\


## ========================================================================== ##
PATH_LEFTBAR_INIT	=	template/leftbar/source/init/
LEFTBAR_INIT		=	init_leftbar.c	\
						init_section.c	\
						init_part_element_1.c	\


## ========================================================================== ##
PATH_LEFTBAR_DISPLAY	=	template/leftbar/source/display/
LEFTBAR_DISPLAY			=	display_leftbar.c	\


## ========================================================================== ##
PATH_LEFTBAR_EVENT		=	template/leftbar/source/event/
LEFTBAR_EVENT			=	event_change_section.c	\



## ========================================================================== ##
PATH_EDITOR		=	source/scene/editor/
EDITOR			=	draw_editor.c	\
					init_editor.c	\


## ========================================================================== ##
PATH_MENU		=	source/scene/menu/
MENU			=	draw_menu.c	\
					init_menu.c	\


## ========================================================================== ##
SRC				=	template/config_init.c	\
					./source/event/world_event.c					\
					./source/event/event_root.c						\
					./source/event/event_area.c						\
					./source/event/event_sun.c						\
					./source/event/event_move_around.c				\
					./source/event/event_move_view.c				\
					./source/event/event_choose_mode.c				\
					./source/event/event_mode_effect.c				\
					./source/event/event_reset.c					\
					./source/event/event_save.c						\
					./source/event/event_load.c						\
					./source/event/read_in.c						\
					./source/event/write_in.c						\
					./source/map/world_maps.c						\
					./source/map/maps_load.c						\
					./source/map/maps_create.c						\
					./source/map/maps_isometric.c					\
					./source/map/maps_fit_into_w.c					\
					./source/map/shade/maps_shade.c					\
					./source/map/shade/shade_color.c				\
					./source/map/shade/shade_shadow.c				\
					./source/map/maps_display.c						\
					./source/map/water/maps_water.c					\
					./source/map/water/water_create.c				\
					./source/map/water/water_restore.c				\
					./source/map/bloc/maps_bloc.c					\
					./source/map/bloc/bloc_create.c					\
					./source/map/bloc/bloc_create_tile.c			\
					./source/map/bloc/bloc_restore.c				\
					./source/map/bloc/bloc_display.c				\
					./source/map/bloc/bloc_wall.c					\
					./source/map/restore/maps_restore.c				\
					./source/map/restore/restore_from_corner.c		\
					./source/map/restore/restore_tile_line.c		\
					./source/map/select_area/world_area.c			\
					./source/map/select_area/area_all_direction.c	\
					./source/map/select_area/area_blue_z.c			\
					./source/map/select_area/area_blue_color.c		\
					./source/map/select_area/area_nearest_pt.c		\
					./source/map/select_area/area_red_z.c			\
					./source/map/select_area/area_red_color.c		\
					./source/map/select_area/area_single_tile.c		\
					./source/window/world_window.c					\
					./source/framebuffer/world_framebuffer.c		\
					./source/framebuffer/framebuffer_circle.c		\
					./source/framebuffer/framebuffer_display.c		\
					./source/process/world_loop.c					\
					main.c \
					$(addprefix $(PATH_INIT), $(INIT))	\
					$(addprefix $(PATH_DISP), $(DISP))	\
					$(addprefix $(PATH_EVENT), $(EVENT))	\
					$(addprefix $(PATH_MENU), $(MENU))	\
					$(addprefix $(PATH_EDITOR), $(EDITOR))	\
					$(addprefix $(PATH_SOURCE_INIT), $(SOURCE_INIT))	\
					$(addprefix $(PATH_SOURCE_EVENT), $(SOURCE_EVENT))	\
					$(addprefix $(PATH_LEFTBAR_INIT), $(LEFTBAR_INIT))	\
					$(addprefix $(PATH_LEFTBAR_DISPLAY), $(LEFTBAR_DISPLAY))	\
					$(addprefix $(PATH_LEFTBAR_EVENT), $(LEFTBAR_EVENT))	\

BIN				= 	my_world

CC				= 	gcc

INCLUDE_DIR		=	include/

CFLAG			=	-I$(INCLUDE_DIR) -g -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
					-lm -Llibrary/ -lcsfml -Llib -ljmy -L ./lib/array/ -larray

DFLAG			=	$(CFLAG) -g -Wall

all:			library $(BIN)

library:
				$(MAKE) -sC ./library/csfml/
				$(MAKE) -sC ./lib/my/
				$(MAKE) -sC ./lib/array/

debug:			$(SRC)
				@$(CC) -o $(BIN) $(SRC) $(DFLAG) -DDEBUG

$(BIN):			$(SRC)
				@$(CC) -o $(BIN) $(SRC) $(CFLAG)

clean:
				$(RM) *.o
				$(MAKE) -C ./library/csfml/ clean
				$(MAKE) -sC ./lib/my/ clean
				$(MAKE) -sC ./lib/array/ clean

fclean:
				@$(RM) $(BIN)
				$(MAKE) -C ./library/csfml/ fclean
				$(MAKE) -sC ./lib/my/ fclean
				$(MAKE) -sC ./lib/array/ fclean

re:				fclean all

.PHONY:			 all, fclean, re, library