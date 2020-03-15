/*
** EPITECH PROJECT, 2020
** world
** File description:
** event_change_element
*/

#include "../template/leftbar/include/leftbar.h"

static void
set_all_other_element_false(left_element_t *element)
{
    for (int i = 0; 2 != i; i++) element[i].active = sfFalse;
}

void
event_change_element(sfRenderWindow *window, left_element_t *element,
left_element_t *all_element)
{
    if (rect_mouse_hovering(window,
    rect_shape_global_bounds(element->shape_button_element)))
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            set_all_other_element_false(all_element);
            element->active = sfTrue;
        }
}

static void
set_all_other_section_false(left_section_t *section)
{
    for (int i = 0; NB_SECTION_ELEMENT_1 != i; i++) section[i].active = sfFalse;
}

void
event_change_section(sfRenderWindow *window, left_section_t *section,
left_section_t *all_section)
{
    if (rect_mouse_hovering(window,
    rect_shape_global_bounds(section->shape_button_section)))
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            set_all_other_section_false(all_section);
            section->active = sfTrue;
        }
}