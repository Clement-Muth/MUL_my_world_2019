/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** show_list
*/

#include "lib_linked_list.h"
#include "../my/my.h"

void show_list(list_t *list)
{
    for (; list != NULL; list = list->next) {
        my_putstr(list->data);
        my_putchar('\n');
    }
    my_putchar('\n');
}