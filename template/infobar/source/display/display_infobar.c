/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** display_infobar
*/

#include "../template/infobar/include/infobar.h"

void
draw_li_section(sfRenderWindow *window, li_t *li, int section)
{
    static int nbr_li_section[] = {7, 5, 5, 3};

    for (int i = 0; nbr_li_section[section] != i; i++) {
        event_hovering_li(window, &li[i]);
        if (li[i].hovering)
            draw_rect_shape(window, li[i].li, NULL);
        sfRenderWindow_drawText(window, li[i].p_li, NULL);
    }
}

void
display_infobar(sfRenderWindow *window, infobar_t *infobar)
{
    for (int i = 0; NB_UL != i; ++i) {
        event_hovering_nav(window, &infobar->nav.section[i]);
        if (infobar->nav.section[i].hovering)
            draw_rect_shape(window, infobar->nav.section[i].section, NULL);
        if (infobar->nav.section[i].div.hovering) {
            draw_rect_shape(window, infobar->nav.section[i].div.div, NULL);
            draw_li_section(window, infobar->nav.section[i].div.li, i);
        }
        draw_text(window, infobar->nav.section[i].p_section, NULL);
    }
}