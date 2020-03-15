/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** create_text
*/

#include "csfml.h"

sfText *
create_text(char *string, char *fontpath, sfColor color, sfVector2f position)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(fontpath);

    if (!font || !text) return (NULL);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, 16);
    sfText_setString(text, string);
    sfText_setPosition(text, position);
    return (text);
}