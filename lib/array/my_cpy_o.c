/*
** EPITECH PROJECT, 2020
** minishell_no_leak
** File description:
** my_cpy_o
*/

#include "array.h"

char *my_cpy_o(char *o)
{
    int e = 0;
    char *cpy = malloc(sizeof(char) * (my_length_o(o) + 1));

    if (cpy == NULL)
        return (NULL);
    for (e = 0; o[e]; e++)
        cpy[e] = o[e];
    cpy[e] = '\0';
    return (cpy);
}