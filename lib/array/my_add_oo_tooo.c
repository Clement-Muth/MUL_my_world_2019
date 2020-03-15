/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_add_oo_tooo
*/

#include "array.h"

char ***my_add_oo_tooo(char ***ooo, char **oo)
{
    int e = 0;
    int length_ooo = my_length_ooo(ooo);
    int length_oo = my_length_oo(oo);
    char ***copy_ooo = malloc(sizeof(char **) * (length_ooo + 2));

    for (; ooo[e] != NULL; e++)
        copy_ooo[e] = ooo[e];
    copy_ooo[e] = malloc(sizeof(char *) * (length_oo + 1));
    copy_ooo[e][0] = NULL;
    for (int i = 1; oo[i] != NULL; i++)
        copy_ooo[e] = my_add_o_too(copy_ooo[e], oo[i]);
    copy_ooo[++e] = NULL;
    free(ooo);
    return (copy_ooo);
}