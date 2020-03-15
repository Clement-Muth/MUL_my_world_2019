/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** open_free
*/

#include "csfml.h"

void
open_free(openf_t *open)
{
    sfText_destroy(open->filename);
    sfText_destroy(open->nofile);
    sfSprite_destroy(open->text_entered);
}