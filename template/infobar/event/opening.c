/*
** EPITECH PROJECT, 2020
** my_world_interface
** File description:
** opening
*/

#include "main.h"

static void close_all(int current, _div_t *div)
{
    for (int i = 0; i != NB_UL; ++i) {
        if (i == current) continue;
        div[i].draw = false;
    }
}

void opening(sfRenderWindow *window, root_t *root)
{
    sfFloatRect rect;
    sfVector2i pos;

    for (int i = 0; i != NB_UL; ++i) {
        rect = sfRectangleShape_getGlobalBounds(root->nav->ul[i].ul);
        pos = sfMouse_getPositionRenderWindow(window);
        if (HOVER) {
            if (sfMouse_isButtonPressed(sfMouseLeft) && !root->nav->div[i].draw) {
                close_all(i, root->nav->div);
                root->nav->div[i].draw = true;
                root->nav->li[i].draw = true;
            }
            else if (sfMouse_isButtonPressed(sfMouseLeft) && root->nav->div[i].draw)
                root->nav->div[i].draw = false;
                root->nav->li[i].draw = false;
        }
    }
}