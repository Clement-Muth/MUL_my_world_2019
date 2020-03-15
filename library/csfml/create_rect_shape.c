/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** create_rect_shape
*/

#include "csfml.h"

sfBool
create_rect_shape(sfRectangleShape **shape, sfVector2f size, sfVector2f position
, sfColor color)
{
    *shape = sfRectangleShape_create();
    if (!*shape) return (sfFalse);
    sfRectangleShape_setSize(*shape, size);
    sfRectangleShape_setPosition(*shape, position);
    sfRectangleShape_setFillColor(*shape, color);
    return (sfTrue);
}