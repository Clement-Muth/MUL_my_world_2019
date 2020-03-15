/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** hovering
*/

#include "my_world.h"

sfBool
event_hovering_button(sfRenderWindow *window, sfSprite *sprite)
{
    sfFloatRect rect_section = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (sfFloatRect_contains(&rect_section, mouse_pos.x, mouse_pos.y)) {
        sfSprite_setTextureRect(sprite, (sfIntRect){0, 42, 155, 42});
        return (sfTrue);
    } else {
        sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 155, 42});
        return (sfFalse);
    }
}