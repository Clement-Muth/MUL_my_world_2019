/*
** EPITECH PROJECT, 2020
** MUL_my_world_object_2019
** File description:
** def_maps
*/

#ifndef DEF_MAPS_H_
#define DEF_MAPS_H_

#define RADIAN(A) (A / 180.0)

#define ABS(V) (V < 0) ? -V : V;

#define CORNER_LEFT map->width * len

#define CORNER_RIGHT map->height * len

#define TEST_TRANS_Y cw->height / 2 - project_iso_point(cw, sqr->c_d_right).y\
        / 2;

#define TEST_TRANS_X cw->width / 2 - (project_iso_point(cw , sqr->c_u_right).x\
        + project_iso_point(cw, sqr->c_d_left).x) / 2;

#define FIND_TRANS_Y cw->height / 2 - project_iso_point(cw, maps->last_tile)\
        .y / 2;

#define FIND_TRANS_X cw->width / 2 - (project_iso_point(cw , maps->map_3d[0]\
        [end_x]).x + project_iso_point(cw, maps->map_3d[end_y][0]).x) / 2;

#define ROTATE_X c_x * cos(cw->ev.rotate_h) - c_y * sin(cw->ev.rotate_h);

#define ROTATE_Y c_y * cos(cw->ev.rotate_h) + c_x * sin(cw->ev.rotate_h);

#define LAST_LINE_X_MAP maps->tile_map[maps->inc_t] = create_line(maps, \
&maps->map_2d[maps->height - 1][x], &maps->map_2d[maps->height - 1][x + 1]);

#define LAST_LINE_Y_MAP maps->tile_map[maps->inc_t] = create_line(maps, \
&maps->map_2d[y][maps->width - 1], &maps->map_2d[y + 1][maps->width - 1]);

#define LAST_LINE_X_WATER maps->wa.line[maps->wa.ic_l] = create_line(maps, \
        &maps->wa.water_2d[maps->height - 1][x], \
        &maps->wa.water_2d[maps->height - 1][x + 1]);

#define LAST_LINE_Y_WATER maps->wa.line[maps->wa.ic_l] = create_line(maps, \
        &maps->wa.water_2d[y][maps->width - 1], &maps->wa.water_2d[y + 1] \
        [maps->width - 1]);

#define PI 3.1415926535

#endif /* !DEF_MAPS_H_ */
