/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** read_in
*/

#include "my_world.h"

float read_float(FILE *f)
{
    float v;

    fread((void *)(&v), sizeof(v), 1, f);
    return (v);
}

sfUint8 read_sfuint8(FILE *f)
{
    sfUint8 i;

    fread((void *)(&i), sizeof(i), 1, f);
    return (i);
}

unsigned int read_int(FILE *f)
{
    unsigned int i;

    fread((void *)(&i), sizeof(i), 1, f);
    return (i);
}

char read_char(FILE *f)
{
    char c;

    fread((void *)(&c), sizeof(c), 1, f);
    return (c);
}