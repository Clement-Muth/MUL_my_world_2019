/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** utilities2
*/

#include "lib.h"

void m_swap(char *str1_ptr, char *str2_ptr)
{
    char temp = *str1_ptr;
    *str1_ptr = *str2_ptr;
    *str2_ptr = temp;
}

char *m_revstr(char *string)
{
    int a = 0;
    int b = 0;

    for (; string[a]; a++);
    --a;
    for (; a >= b; ++b, --a)
        m_swap(&string[a], &string[b]);
    return (string);
}

int m_intlen(int number)
{
    int i = 0;

    for (; (number /= 10) != 0; ++i);
    return (i + 1);
}