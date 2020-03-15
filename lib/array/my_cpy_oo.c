/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cpy_oo
*/

#include "array.h"
#include "../my/my.h"

char **my_cpy_oo(char **oo)
{
    int e = 0;
    int i = 0;
    char **cpy = malloc(sizeof(char *) * (my_length_oo(oo) + 1));

    if (cpy == NULL)
        return (NULL);
    for (e = 0; oo[e] != NULL; e++) {
        cpy[e] = malloc(sizeof(char) * (my_length_o(oo[e]) + 1));
        if (cpy[e] == NULL)
            return (NULL);
        for (i = 0; oo[e][i] != '\0'; i++)
            cpy[e][i] = oo[e][i];
        cpy[e][i] = '\0';
    }
    cpy[e] = NULL;
    return (cpy);
}