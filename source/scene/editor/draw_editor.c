/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** draw_editor
*/

#include "my_world.h"

void
draw_editor(sfRenderWindow *window, root_t *root, template_t *template,
map_t *map, event_t *event)
{
    draw_template(window, template, map, event);
}