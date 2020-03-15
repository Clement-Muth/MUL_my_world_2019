/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** def_area
*/

#ifndef DEF_AREA_H_
#define DEF_AREA_H_

#define VERIFY ci->near.x + i < maps->width && ci->near.y + i < maps->height\
        && ci->near.x - i >= 0 &&  ci->near.y - i >= 0

#define IF_INC_X length_vector\
        (ci->area.co, maps->map_3d[ci->near.y + i][ci->near.x + i])\
        < ci->area.radius

#define IF_INC_Y length_vector\
        (ci->area.co, maps->map_3d[ci->near.y + i][ci->near.x - i])\
        < ci->area.radius

#define IF_DEC_X length_vector(ci->area.co, \
        maps->map_3d[ci->near.y - i][ci->near.x - i]) < ci->area.radius

#define IF_DEC_Y length_vector(ci->area.co, \
        maps->map_3d[ci->near.y - i][ci->near.x + i]) < ci->area.radius

#endif /* !DEF_AREA_H_ */
