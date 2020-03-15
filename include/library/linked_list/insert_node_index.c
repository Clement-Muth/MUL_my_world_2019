/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** insert_node_insert
*/

#include "lib_linked_list.h"

void insert_node_index(list_t **list, list_t *element, int index)
{
    list_t *save = *list;

    if (index == 0 || save == NULL) {
        element->next = *list;
        *list = element;
        return;
    } else if (index < 0)
        return;
    for (int i = 0; i < index - 1 && save->next != NULL; save = save->next)
        i++;
    element->next = save->next;
    save->next = element;
}