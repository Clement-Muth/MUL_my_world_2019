/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_rm_o_too
*/

#include "array.h"
#include "../my/my.h"

static char *cpy_with_limit(char *original, char lim)
{
    int e = 0;
    char *copy = malloc(sizeof(char) * (my_length_lim(original, lim, 0) + 1));

    for (e = 0; original[e] != '\0' && original[e] != lim; e++)
        copy[e] = original[e];
    copy[e] = '\0';
    return (copy);
}

static int compare_two_str(char *s1, char *s2)
{
    int e = 0;

    for (; s1[e] != '\0' || s2[e] != '\0'; e++) {
        if (s1[e] < s2[e]) {
            return (-1);
        } else if (s1[e] > s2[e]) {
            return (1);
        }
    }
    return (0);
}

char **my_rm_o_too(char **oo, char *o)
{
    int e = 0;
    int ce = 0;
    int length_oo = my_length_oo(oo);
    char *tmp;
    char **copy_oo = malloc(sizeof(char *) * (length_oo + 1));

    if (copy_oo == NULL)
        return (NULL);
    for (; oo[e] != NULL; e++) {
        tmp = cpy_with_limit(oo[e], '=');
        if (compare_two_str(tmp, o) == 0) {
            free(tmp);
            continue;
        }
        copy_oo[ce++] = my_cpy_o(oo[e]);
        free(tmp);
    }
    copy_oo[ce] = NULL;
    my_free_oo(oo);
    return (copy_oo);
}