/*
** EPITECH PROJECT, 2020
** new_interface
** File description:
** event_click_nav
*/

#include "../template/infobar/include/infobar.h"

void
event_click_nav(sfRenderWindow *window, li_t li, int i)
{
    if (0 == i) createf(window);
    if (2 == i) openf();
    if (6 == i) window_close(window);
}