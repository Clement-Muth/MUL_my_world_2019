/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_add_o_too
*/

#include "array.h"

char **my_add_o_too(char **oo, char *o)
{
    int e = 0;
    int i = 0;
    int length = my_length_oo(oo);
    char **copy_oo = malloc(sizeof(char *) * (length + 2));

    if (copy_oo == NULL)
        return (NULL);
    for (e = 0; oo[e] != NULL; e++) {
        copy_oo[e] = my_cpy_o(oo[e]);
        if (copy_oo[e] == NULL)
            return (NULL);
    }
    copy_oo[e++] = o;
    copy_oo[e] = NULL;
    my_free_oo(oo);
    return (copy_oo);
}