/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** remove_node_end
*/

#include "lib_linked_list.h"

void remove_node_end(list_t **list)
{
    list_t *save = *list;

    if (save == NULL)
        return;
    if (save->next == NULL) {
        *list = NULL;
        return;
    }
    for (; save->next->next != NULL; save = save->next);
    save->next = NULL;
}