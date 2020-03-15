/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** create_text
*/

#include "csfml.h"

sfText *
create_text_from_file(char *string, char *fontpath, FILE *stream, \
sfVector2f position)
{
    static size_t size_read = 500;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(fontpath);

    if (!stream || !font || !text) return (NULL);
    string = NULL;
    getline(&string, &size_read, stream);
    sfText_setFont(text, font);
    sfText_setColor(text, LIGHT_GREY);
    sfText_setCharacterSize(text, 16);
    sfText_setString(text, string);
    sfText_setPosition(text, position);
    return (text);
}