/*
** EPITECH PROJECT, 2020
** world
** File description:
** create_sprite
*/

#include "csfml.h"

sfSprite *
create_sprite(char *texture_file_name, sfVector2f position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(texture_file_name, NULL);

    if (!sprite || !texture) return (NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, position);
    return (sprite);
}