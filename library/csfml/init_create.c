/*
** EPITECH PROJECT, 2020
** re
** File description:
** init_create
*/

#include "csfml.h"

int
event_write(int i, sfText *text, char *str, char data)
{
    if (sfKeyboard_isKeyPressed(sfKeyBack)) {
        if (i - 1 >= 0) {
            --i;
            str[i] = '\0';
            sfText_setString(text, str);
        }
    }
    if (!PREG_MATCH) return (i);
    else if (i != 20) {
        str[i] = data;
        str[i + 1] = '\0';
        sfText_setString(text, str);
        ++i;
    }
    return (i);
}

void
init_create(createf_t *create, char *filename)
{
    printf("init\n");
    create->filename = filename;
    create->new = 0;
}