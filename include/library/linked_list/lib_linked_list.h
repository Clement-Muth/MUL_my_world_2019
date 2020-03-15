/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** lib_linked_list
*/

#ifndef LIB_LINKED_LIST_H_
#define LIB_LINKED_LIST_H_

#include <stdlib.h>

typedef struct list_s
{
    int nb;
    char *data;
    struct list_s *next;
}list_t;

void show_list(list_t *list);
list_t *create_node(char *got);
void insert_node_index(list_t **list, list_t *element, int index);
void remove_node_index(list_t **list, int index);
void fill_list(list_t **list, char **argv, int argc);
void insert_node_end(list_t **list, list_t *element);
unsigned int list_length(list_t *list);
void remove_node_begin(list_t **list);
void remove_node_end(list_t **list);
list_t *get_node_index(list_t *list, int index);

#endif /* !LIB_LINKED_LIST_H_ */
