/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** config_init
*/

#include "my_world.h"

void
destroy_template(sfRenderWindow *window, template_t *template)
{
    sfRectangleShape_destroy(template->infobar.nav.navbar);
    for (int i = 0; NB_UL != i; ++i) {
        sfText_destroy(template->infobar.nav.section[i].p_section);
        sfRectangleShape_destroy(template->infobar.nav.section[i].section);
    }
    free(template->infobar.nav.section);
    sfRenderWindow_destroy(window);
}

bool
init_template(sfRenderWindow *window, template_t *template)
{
    if (!init_leftbar(window, &template->leftbar)) return (false);
    if (!init_infobar(window, &template->infobar)) return (false);
    return (true);
}

void
draw_template(sfRenderWindow *window, template_t *template, map_t *maps,
event_t *event)
{
    display_leftbar(window, &template->leftbar, maps, event);
    display_infobar(window, &template->infobar);
}