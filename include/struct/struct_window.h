/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** struct_window
*/

#ifndef STRUCT_WINDOW_H_
#define STRUCT_WINDOW_H_

#include <SFML/Graphics.h>
#include "struct_event.h"

typedef struct fbf_s
{
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
}fbf_t;

typedef struct frame_s
{
    sfClock *clock;
    sfTime time;
    double framerate;
    float tmp_frame;
    double sec;
}frame_t;

typedef struct cw_s
{
    fbf_t *buffer;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfVideoMode video_mode;
    sfEvent event;
    event_t ev;
    frame_t ti;
    int height;
    int width;
}cw_t;

#endif /* !STRUCT_WINDOW_H_ */