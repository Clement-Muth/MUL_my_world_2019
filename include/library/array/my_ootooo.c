/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_ootooo
*/

#include "array.h"

char ***my_ootooo(char **oo, char sep_one, char sep_two)
{
    int e = 0;
    int nb;
    int length = my_length_oo(oo);
    char ***ooo = malloc(sizeof(char **) * (length + 1));

    if (ooo == NULL)
        return (NULL);
    for (e = 0; e < length; e++)
        ooo[e] = my_otoo(oo[e], sep_one, sep_two, &nb);
    ooo[e] = NULL;
    return (ooo);
}