/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** fill_list
*/

#include "lib_linked_list.h"

void fill_list(list_t **list, char **argv, int argc)
{
    for (int e = argc - 1; e > 0; e--) {
        insert_node_index(list, create_node(argv[e]), 0);
    }
}