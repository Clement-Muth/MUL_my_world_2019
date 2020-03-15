/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** get_node_index
*/

#include "lib_linked_list.h"

list_t *get_node_index(list_t *list, int index)
{
    int i = 0;

    for (; list != NULL && i < index; list = list->next)
        i++;
    if (list == NULL) {
        return (NULL);
    }
    return (list);
}