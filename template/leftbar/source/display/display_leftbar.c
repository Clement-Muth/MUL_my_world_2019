/*
** EPITECH PROJECT, 2020
** world
** File description:
** display_leftbar
*/

#include "../template/leftbar/include/leftbar.h"

static void
draw_section(sfRenderWindow *window, left_section_t *section,
left_section_t *all_section, int i)
{
    event_change_section(window, section, all_section);
    if (section->active) draw_sprite(window, section->sprite, NULL);
}

static void
draw_element(sfRenderWindow *window, left_element_t *element,
left_element_t *all_element, int i)
{
    static int nb_section[] = {3, 1, 1};

    event_change_element(window, element, all_element);
    if (element->active) {
        for (int n = 0; nb_section[i] != n; n++)
            draw_section(window, &element->section[n], element->section, n);
    }
}

static void
event_element_1(sfRenderWindow *window, leftbar_t *leftbar, map_t *map,
event_t *event)
{
    for (int i = 0; i != 12; i++) {
        if (!leftbar->element[0].section[0].active) break;
        if (!rect_mouse_hovering(window,
        rect_shape_global_bounds(leftbar->element[0].section[0]. \
        part[i].shape_button_part))) continue;
        if (button_pressed(sfMouseLeft))
            map->ci.new_clr = leftbar->element[0].section[0].part[i].part_color;
    }
    for (int i = 0; i != 2; i++) {
        if (!leftbar->element[0].section[1].active) break;
        if (!rect_mouse_hovering(window,
        rect_shape_global_bounds(leftbar->element[0].section[1].part[i].\
        shape_button_part))) continue;
        if (button_pressed(sfMouseLeft)) event->select_effect = i + 1;
    }
}

void
display_leftbar(sfRenderWindow *window, leftbar_t *leftbar, map_t *map,
event_t *event)
{
    for (int i = 0; i != 2; i++)
        draw_element(window, &leftbar->element[i], leftbar->element, i);
    event_element_1(window, leftbar, map, event);
}