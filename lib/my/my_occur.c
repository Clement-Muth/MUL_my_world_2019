/*
** EPITECH PROJECT, 2020
** minishell_no_leak
** File description:
** my_recur
*/

#include "my.h"

int my_occur(char *str, char element)
{
    int inc = 0;
    int occurence = 0;

    for (inc = 0; str[inc]; inc++)
        if (str[inc] == element)
            occurence++;
    return (occurence);
}