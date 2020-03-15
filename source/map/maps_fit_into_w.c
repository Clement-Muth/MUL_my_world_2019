/*
** EPITECH PROJECT, 2020
** MUL_my_world_object_2019
** File description:
** maps_square
*/

#include "my_world.h"

static void get_value_square(square_t *sqr, cw_t *cw, map_t *map, int len)
{
    sqr->c_u_right = (sfVector3f){CORNER_LEFT, 0, 0};
    sqr->c_d_right = (sfVector3f){CORNER_LEFT, CORNER_RIGHT, 0};
    sqr->c_u_left = (sfVector3f){0, 0, 0};
    sqr->c_d_left = (sfVector3f){0, CORNER_RIGHT, 0};
    sqr->mv_test.y = TEST_TRANS_Y;
    sqr->mv_test.x = TEST_TRANS_X;
}

static int check_corner_in_window(cw_t *cw, square_t *sqr, sfVector3f corner)
{
    sfVector2f corner_2d = {.x = 0, .y = 0};

    corner_2d = project_iso_point(cw, corner);
    corner_2d.x += sqr->mv_test.x;
    corner_2d.y += sqr->mv_test.y;
    if (corner_2d.x < 0 || corner_2d.x > (cw->width - (cw->width / 10)) ||
    corner_2d.y < 0 || corner_2d.y > (cw->height - (cw->height / 10)))
        return (1);
    return (0);
}

int find_square_value(cw_t *cw, map_t *map)
{
    square_t sqr;
    int len = 90;
    int here = 1;

    for (len = 90; len > 0; --len) {
        get_value_square(&sqr, cw, map, len);
        if (check_corner_in_window(cw, &sqr, sqr.c_d_left) != 0) continue;
        if (check_corner_in_window(cw, &sqr, sqr.c_u_left) != 0) continue;
        if (check_corner_in_window(cw, &sqr, sqr.c_d_right) != 0) continue;
        if (check_corner_in_window(cw, &sqr, sqr.c_u_right) != 0) continue;
        if (here) break;
    }
    return (len);
}