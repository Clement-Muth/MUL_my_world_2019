/*
** EPITECH PROJECT, 2020
** minishell_no_leak
** File description:
** my_putc
*/

#include "array.h"

void my_putc(char c)
{
    write(1, &c, 1);
}