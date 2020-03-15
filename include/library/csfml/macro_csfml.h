/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** macro
*/

#ifndef MACRO_CSFML_H_
#define MACRO_CSFML_H_

#define CONTEXT_W sfRenderWindow_getViewport(window, \
    sfRenderWindow_getDefaultView(window)).width
#define CONTEXT_H sfRenderWindow_getViewport(window, \
    sfRenderWindow_getDefaultView(window)).height
#define MID_VIEWPORT 425, CONTEXT_H / 2

#define PREG_MATCH ((data >= 'a' && data <= 'z') || (data >= 'A' && \
data <= 'Z') || (data >= '0' && data <= '9'))
#define SIZE_VERIF(data) ((data >= '0' && data <= '9') ? (sfTrue) : (sfFalse))
#define TITLE_VERIF(data) (((data >= 'a' && data <= 'z') || (data >= 'A' && \
data <= 'Z') || (data >= '0' && data <= '9')) ? (sfTrue) : (sfFalse))

#endif /* !MACRO_CSFML_H_ */