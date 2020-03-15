/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** init_section_hovering
*/

#include "../template/infobar/include/infobar.h"

void
init_section_hovering(sfRectangleShape **shape)
{
    static unsigned x = -50 * NB_UL;

    create_rect_shape(shape, (sfVector2f){50, 30}, (sfVector2f){x, 0}, \
    HOVERING);
    x += 50;
}