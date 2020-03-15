/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** remove_node_insert
*/

#include "lib_linked_list.h"

void remove_node_index(list_t **list, int index)
{
    list_t *save = *list;
    list_t *tmp;

    if (index < 0 || save == NULL)
        return;
    else if (index == 0 || save->next == NULL) {
        *list = NULL;
        return;
    }
    for (int i = 0; i < index - 1 && save->next != NULL; save = save->next)
        i++;
    tmp = save->next->next;
    save->next = tmp;
}