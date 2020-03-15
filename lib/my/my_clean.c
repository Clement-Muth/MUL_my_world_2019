/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_clean
*/

#include "my.h"

static int no_more(char *str, clean_t *cl)
{
    for (; str[cl->e]; ++cl->e) {
        if (str[cl->e] != cl->one && str[cl->e] != cl->two)
            return (0);
    }
    return (1);
}

static int end_blocks(char *str, clean_t *cl)
{
    if ((str[cl->e] == cl->one || str[cl->e] == cl->two) && cl->block == 0) {
        if (no_more(str, cl) == 1)
            return (1);
        str[cl->i] = cl->one;
        ++cl->i;
        cl->block = 1;
    }
    return (0);
}

static clean_t init_clean(char one, char two)
{
    clean_t cl;

    cl.i = 0;
    cl.e = 0;
    cl.one = one;
    cl.two = two;
}

void my_cleanstr(char *str, char one, char two)
{
    clean_t cl = init_clean(one, two);

    for (;str[cl.e] == cl.one || str[cl.e] == cl.two; ++cl.e);
    for (; str[cl.e]; ++cl.e) {
        if (end_blocks(str, &cl) == 1) {
            break;
        } else if (str[cl.e] != cl.one && str[cl.e] != cl.two && cl.block == 1)
            cl.block = 0;
        if (str[cl.e] != cl.one && str[cl.e] != cl.two)
            str[cl.i++] = str[cl.e];
    }
    str[cl.i] = '\0';
}

void my_clean(char *str, char one, char two)
{
    int e = 0;
    int i = 0;

    for (; str[e]; ++e)
        if (str[e] != one && str[e] != two)
            str[i++] = str[e];
    str[i] = '\0';
}