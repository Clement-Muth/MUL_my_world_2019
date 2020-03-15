/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** framebuffer_circle
*/

#include "my_world.h"

void put_select_area_red(cw_t *cw, map_t *maps, circle_t *area)
{
    sfVector2f area_2d;
    sfVector3f area_3d;
    double conversion = PI / 180;
    double inc = (40 / area->radius);

    area->co = invers_project_no_rotate(cw, maps, sfMPos(cw->window));
    for (double e = 0; e < 360; e += inc) {
        area_3d.x =  area->radius * cos(e * conversion) + area->co.x;
        area_3d.y = area->radius * sin(e * conversion) + area->co.y;
        area_3d.z = 0;
        area_2d = project_iso_point(cw, area_3d);
        area_2d.x += maps->move.x;
        area_2d.y += maps->move.y;
        put_pixel(cw->buffer, area_2d.x, area_2d.y, sfRed);
    }
}

void put_select_area_blue(cw_t *cw, map_t *maps, circle_t *area)
{
    sfVector2f circle;
    sfVector2i mouse = sfMPos(cw->window);
    double conversion = PI / 180;
    double inc = (40 / area->radius);

    area->co.x = mouse.x;
    area->co.y = mouse.y;
    for (double e = 0; e < 360; e += inc) {
        circle.x =  area->radius * cos(e * conversion) + area->co.x;
        circle.y = area->radius * sin(e * conversion) + area->co.y;
        put_pixel(cw->buffer, circle.x, circle.y, sfBlue);
    }
}