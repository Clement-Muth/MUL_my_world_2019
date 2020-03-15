/*
** EPITECH PROJECT, 2019
** my comp
** File description:
** comp
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}