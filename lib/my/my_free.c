/*
** EPITECH PROJECT, 2020
** minishell_no_leak
** File description:
** my_free
*/

#include "my.h"
#include <stdlib.h>

void my_free(char *one, char *two, char *three, int release)
{
    if (release - 5 >= 0) {
        release -= 5;
        free(three);
    }
    if (release - 3 >= 0) {
        release -= 3;
        free(two);
    }
    if (release - 1 >= 0) {
        release -= 1;
        free(one);
    }
}