/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** maps_color
*/

#include "my_world.h"

static void shade_ic_calcul(shade_t *sh)
{
    float dhigh = 0;

    for (int e = 0; e < sh->ic_s - 1; ++e) {
        dhigh = sh->stage[e + 1].high - sh->stage[e].high;
        sh->stage[e].ic_r = (sh->stage[e + 1].cl.r - sh->stage[e].cl.r) / dhigh;
        sh->stage[e].ic_g = (sh->stage[e + 1].cl.g - sh->stage[e].cl.g) / dhigh;
        sh->stage[e].ic_b = (sh->stage[e + 1].cl.b - sh->stage[e].cl.b) / dhigh;
    }
}

static void default_init_color(shade_t *sh)
{
    sh->stage[0] = (stage_t){(sfColor){75, 55, 29, 255}, -200, 0, 0, 0};
    sh->stage[1] = (stage_t){(sfColor){200, 170, 80, 255}, -30, 0, 0, 0};
    sh->stage[2] = (stage_t){(sfColor){6, 150, 21, 255}, 20, 0, 0, 0};
    sh->stage[3] = (stage_t){(sfColor){76, 76, 76, 255}, 300, 0, 0, 0};
    sh->stage[4] = (stage_t){(sfColor){220, 220, 220, 255}, 400, 0, 0, 0};
}

int init_shade(shade_t *shade)
{
    shade->ic_s = 5;
    shade->sun_power = 25;
    shade->sun_rise = PI / 2;
    shade->ic = (sfVector2i){0, 0};
    shade->co = (sfVector2i){0, 0};
    shade->sun = (sfVector3f){0, 1, 0};
    shade->stage = malloc(sizeof(stage_t) * 5);
    if (shade->stage == NULL)
        return (1);
    default_init_color(shade);
    shade_ic_calcul(shade);
    return (0);
}

void shade_destroy(shade_t *shade)
{
    free(shade->stage);
}