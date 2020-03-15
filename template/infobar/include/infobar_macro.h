/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** infobar_macro
*/

#ifndef INFOBAR_MACRO_H_
#define INFOBAR_MACRO_H_

#define CONTEXT_W sfRenderWindow_getViewport(window, \
    sfRenderWindow_getDefaultView(window)).width
#define CONTEXT_H sfRenderWindow_getViewport(window, \
    sfRenderWindow_getDefaultView(window)).height
#define SET_W(size) ((CONTEXT_W * size) / 100)
#define SET_H(size) ((CONTEXT_H * size) / 100)
#define VIEWPORT 1920, 1080, 32
#define MID_VIEWPORT 425, CONTEXT_H / 2
#define HOVER ((pos.y < (rect.top + rect.height) && pos.y > rect.top && \
    pos.x < (rect.left + rect.width) && pos.x > rect.left) ? (true) : (false))

#endif /* !INFOBAR_MACRO_H_ */