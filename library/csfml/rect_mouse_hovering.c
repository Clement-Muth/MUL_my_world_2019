/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** rect_mouse_hovering
*/

#include "csfml.h"

sfBool
rect_mouse_hovering(sfRenderWindow *window, sfFloatRect rect)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    return (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) ?
    (sfTrue) : (sfFalse);
}