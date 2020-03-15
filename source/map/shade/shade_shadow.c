/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** shade_shadow
*/

#include "my_world.h"

void cross(sfVector3f *a, sfVector3f *b, sfVector3f *n)
{
    n->x = a->y * b->z - a->z * b->y;
    n->y = (a->x * b->z - a->z * b->x) * -1;
    n->z = a->x * b->y - a->y * b->x;
}

void normalize(sfVector3f *n)
{
    sfVector3f abs = {fabs(n->x), fabs(n->y), fabs(n->z)};

    if (abs.x >= abs.y && abs.x >= abs.z && abs.x != 0) {
        n->y /= abs.x;
        n->z /= abs.x;
        n->x = (n->x >= 0) ? 1 : -1;
        return;
    }
    if (abs.y >= abs.x && abs.y >= abs.z && abs.y != 0) {
        n->x /= abs.y;
        n->z /= abs.y;
        n->y = (n->y >= 0) ? 1 : -1;
        return;
    }
    if (abs.z >= abs.x && abs.z >= abs.y && abs.z != 0) {
        n->x /= abs.z;
        n->y /= abs.z;
        n->z = (n->z >= 0) ? 1 : -1;
        return;
    }
}

float dot(sfVector3f *n, sfVector3f *sun)
{
    return (n->x * sun->x + n->y * sun->y + n->z * sun->z);
}

sfVector3f vector(sfVector3f one, sfVector3f two, float angle)
{
    sfVector2f first = {one.x * cos(angle) + one.y * sin(angle),
    one.y * cos(angle) - one.x * sin(angle)};
    sfVector2f second = {two.x * cos(angle) + two.y * sin(angle),
    two.y * cos(angle) - two.x * sin(angle)};
    sfVector3f a = {second.x - first.x, second.y - first.y, two.z - one.z};

    return (a);
}

sfColor shade_shadow(cw_t *cw, sfVector3f **map_3d, shade_t *sh, sfColor cl)
{
    float add = 0;
    float res = 0;
    sfVector3f a = vector(map_3d[sh->co.y][sh->co.x],
    map_3d[sh->co.y + sh->ic.y][sh->co.x + sh->ic.x], cw->ev.rotate_h);
    sfVector3f b = vector(map_3d[sh->co.y][sh->co.x + sh->ic.x],
    map_3d[sh->co.y + sh->ic.y][sh->co.x], cw->ev.rotate_h);
    sfVector3f n = {0, 0, 0};

    cross(&a, &b, &n);
    normalize(&n);
    res = dot(&n, &sh->sun) + 1;
    add = res * sh->sun_power;
    if (add + cl.r > 0 && add + cl.r < 255)
        cl.r += add;
    if (add + cl.g > 0 && add + cl.g < 255)
        cl.g += add;
    if (add + cl.b > 0 && add + cl.b < 255)
        cl.b += add;
    return (cl);
}