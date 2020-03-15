/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** poll_hovering_button
*/

#include "my_world.h"

static void
hovering_template(sfRenderWindow *window, template_t *template)
{
    int nbr_li[] = {7, 5, 5, 3, '\0'};

    for (int i = 0; NB_UL != i ; i++) {
        if (template->infobar.nav.section[i].hovering && \
            button_pressed(sfMouseLeft))
            template->infobar.nav.section[i].div.hovering = sfTrue;
        else if (template->infobar.nav.section[i].div.hovering && \
            button_pressed(sfMouseLeft) && \
            close_div(window, template->infobar.nav.section[i].div.div))
            template->infobar.nav.section[i].div.hovering = sfFalse;
    }
    for (int i = 0; NB_UL != i; i++) {
        for (int n = 0; nbr_li[i] != n; n++) {
            if (template->infobar.nav.section->div.li[n].hovering && \
            sfMouse_isButtonPressed(sfMouseLeft))
                event_click_nav(window, \
                template->infobar.nav.section->div.li[n], n);
        }
    }
}

void
poll_hovering_button(sfRenderWindow *window, root_t *root, template_t *template)
{
    if (key_pressed(sfKeyLControl) && \
    key_pressed(sfKeyN) || event_hovering_button(window, root->menu.sprite[1]) \
    && sfMouse_isButtonPressed(sfMouseLeft)) createf(window);
    if (key_pressed(sfKeyLControl) && \
    key_pressed(sfKeyO) || event_hovering_button(window, root->menu.sprite[2]) \
    && sfMouse_isButtonPressed(sfMouseLeft)) openf();
    hovering_template(window, template);
}