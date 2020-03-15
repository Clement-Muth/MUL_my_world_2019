/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** hovering
*/

#include "../template/infobar/include/infobar.h"

void
event_hovering_li(sfRenderWindow *window, li_t *li)
{
    sfFloatRect rect_section = rect_shape_global_bounds(li->li);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (sfFloatRect_contains(&rect_section, mouse_pos.x, mouse_pos.y))
        li->hovering = sfTrue;
    else if (li->hovering)
        li->hovering = sfFalse;
}

sfBool
close_div(sfRenderWindow *window, sfRectangleShape *div)
{
    sfFloatRect rect_div = rect_shape_global_bounds(div);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    return (sfFloatRect_contains(&rect_div, mouse_pos.x, mouse_pos.y))
    ? (sfFalse) : (sfTrue);
}

static void
hovering_section(sfRenderWindow *window, section_t *section)
{
    sfFloatRect rect_section = rect_shape_global_bounds(section->section);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (sfFloatRect_contains(&rect_section, mouse_pos.x, mouse_pos.y))
        section->hovering = sfTrue;
    else if (section->hovering)
        section->hovering = sfFalse;
}

void
event_hovering_nav(sfRenderWindow *window, section_t *section)
{
    hovering_section(window, section);
}