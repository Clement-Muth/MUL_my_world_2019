/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** remove_node_begin
*/

#include "lib_linked_list.h"

void remove_node_begin(list_t **list)
{
    list_t *save;

    if (*list == NULL)
        return;
    save = (*list)->next;
    *list = save;
}