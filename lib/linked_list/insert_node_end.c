/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** insert_node_end
*/

#include "lib_linked_list.h"

void insert_node_end(list_t **list, list_t *element)
{
    list_t *save = *list;

    if (save == NULL) {
        element->next = save;
        *list = element;
        return;
    }
    for (; save->next != NULL; save = save->next);
    element->next = NULL;
    save->next = element;
}