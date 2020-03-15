/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** draw_menu
*/

#include "my_world.h"

void
draw_menu(sfRenderWindow *window, root_t *root, template_t *template)
{
    for (int i = 0; i != 3; i++) {
        sfRenderWindow_drawSprite(window, root->menu.sprite[i], NULL);
        if (i >= 1 && i <= 2)
            event_hovering_button(window, root->menu.sprite[i]);
    }
}