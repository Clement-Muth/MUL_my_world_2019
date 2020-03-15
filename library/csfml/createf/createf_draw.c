/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** createf_draw
*/

#include "csfml.h"

void
createf_draw(sfRenderWindow *window, createf_t create)
{
    for (int i = 1; i != NB_ELEMENT; i++) {
        if (i == 3 && create.string[3]) {
            sfRenderWindow_drawText(window, create.text[3], NULL);
            break;
        }
        if (create.string[i])
            sfRenderWindow_drawText(window, create.text[i], NULL);
    }
    if (create.wrong_info_file) sfRenderWindow_drawText(window, create.error, NULL);
}