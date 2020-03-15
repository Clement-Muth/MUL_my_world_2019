/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** create_node
*/

#include "lib_linked_list.h"

list_t *create_node(char *got)
{
    list_t *element = malloc(sizeof(list_t));

    element->data = got;
    return (element);
}