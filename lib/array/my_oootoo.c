/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_oootoo
*/

#include "array.h"
#include "../my/my.h"

static char *cat_three(char *one, char *two, char *three)
{
    int inc_s = 0;
    char *sum = malloc(my_length_o(one) + my_length_o(two) +
    my_length_o(three) + 1);

    if (sum == NULL)
        return (NULL);
    for (int e = 0; one[e] != '\0'; e++, inc_s++)
        sum[inc_s] = one[e];
    for (int i = 0; two[i] != '\0'; i++, inc_s++)
        sum[inc_s] = two[i];
    for (int o = 0; three[o] != '\0'; o++, inc_s++)
        sum[inc_s] = three[o];
    sum[inc_s] = '\0';
    return (sum);
}

static char *cpy(char *str)
{
    int e = 0;
    char *cpy = malloc(sizeof(char) * (my_length_o(str) + 1));

    for (e = 0; str[e]; e++)
        cpy[e] = str[e];
    cpy[e] = '\0';
    return (cpy);
}

static char *cat_two(char *one, char *two)
{
    int inc_s = 0;
    char *sum = malloc(sizeof(char) * (my_strlen(one) + my_strlen(two) + 1));

    for (int e = 0; one[e] != '\0'; e++, inc_s++)
        sum[inc_s] = one[e];
    for (int i = 0; two[i] != '\0'; i++, inc_s++)
        sum[inc_s] = two[i];
    sum[inc_s] = '\0';
    return (sum);
}

void inside_oootoo(oootoo_t *inc, char ***ooo, char **oo, char link[2])
{
    if (inc->i != 0)
        oo[inc->e] = cat_three(oo[inc->e], link, ooo[inc->e][inc->i]);
    else
        oo[inc->e] = cpy(ooo[inc->e][inc->i]);
}

char **my_oootoo(char ***ooo, char relate_one)
{
    oootoo_t inc;
    int length = my_length_ooo(ooo);
    char link[2] = {relate_one, '\0'};
    char **oo = malloc(sizeof(char *) * (length + 1));

    inc.e = 0;
    inc.i = 0;
    for (inc.e = 0; ooo[inc.e] != NULL; inc.e++) {
        for (inc.i = 0; ooo[inc.e][inc.i] != NULL; inc.i++)
            inside_oootoo(&inc, ooo, oo, link);
        if (inc.i == 1)
            oo[inc.e] = cat_two(oo[inc.e], link);
    }
    oo[inc.e] = NULL;
    return (oo);
}