/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** list_length
*/

#include "lib_linked_list.h"

unsigned int list_length(list_t *list)
{
    unsigned int length = 0;

    for (; list != NULL; list = list->next)
        length++;
    return (length);
}