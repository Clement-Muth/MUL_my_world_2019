/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** redefine_function_name
*/

#ifndef REDEFINE_FUNCTION_NAME_H_
#define REDEFINE_FUNCTION_NAME_H_

#define draw_rect_shape sfRenderWindow_drawRectangleShape
#define draw_text sfRenderWindow_drawText
#define draw_sprite sfRenderWindow_drawSprite
#define font_size sfText_setCharacterSize

#define rect_shape_color sfRectangleShape_setFillColor
#define rect_shape_size sfRectangleShape_setSize
#define rect_shape_global_bounds sfRectangleShape_getGlobalBounds
#define rect_shape_position sfRectangleShape_setPosition

#define button_pressed sfMouse_isButtonPressed
#define key_pressed sfKeyboard_isKeyPressed
#define window_close sfRenderWindow_close
#define window_setcursor sfRenderWindow_setMouseCursor
#define create_cursor sfCursor_createFromSystem

#define sprite_set_pos sfSprite_setPosition
#define sprite_set_trec sfSprite_setTextureRect
#define sprite_global_b sfSprite_getGlobalBounds

#endif /* !REDEFINE_FUNCTION_NAME_H_ */