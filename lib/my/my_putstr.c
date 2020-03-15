/*
** EPITECH PROJECT, 2019
** putstr
** File description:
** put
*/

#include "my.h"
#include <unistd.h>
#include "color.h"
#include <stdlib.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

int nl_putstr(char *str)
{
    write(1, str, my_strlen(str));
    free(str);
}

void my_putrstr(char *str, int release)
{
    write(2, str, my_strlen(str));
    my_free(str, NULL, NULL, release);
}

void my_putcstr(char *str, char *color, int option, int release)
{
    my_putstr("\033[");
    my_put_nbr(option);
    my_putstr(color);
    my_putstr(str);
    my_putstr(RESET);
    my_free(str, NULL, NULL, release);
}