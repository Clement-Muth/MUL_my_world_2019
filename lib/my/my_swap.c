/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_swap
*/

#include "my.h"

void my_swapi(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void my_swapo(float *a, float *b)
{
    float e = *a;
    *a = *b;
    *b = e;
}