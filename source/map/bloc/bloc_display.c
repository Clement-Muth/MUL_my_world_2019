/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** bloc_display
*/

#include "my_world.h"

void bloc_display(cw_t *cw, bloc_t *bloc)
{
    for (int ic = 0; ic < bloc->ic_t; ++ic) {
        sfRenderWindow_drawVertexArray(cw->window, bloc->water[ic], NULL);
        sfRenderWindow_drawVertexArray(cw->window, bloc->tile[ic], NULL);
    }
    for (int ic = 0; ic < bloc->ic_l && cw->ev.line_on == 1; ++ic)
        sfRenderWindow_drawVertexArray(cw->window, bloc->line[ic], NULL);
}