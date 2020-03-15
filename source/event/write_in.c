/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** write_in
*/

#include "my_world.h"

void write_float(float v, FILE *f)
{
    fwrite((void *)(&v), sizeof(v), 1, f);
}

void write_sfuint8(sfUint8 i, FILE *f)
{
    fwrite((void *)(&i), sizeof(i), 1, f);
}

void write_int(int i, FILE *f)
{
    fwrite((void *)(&i), sizeof(i), 1, f);
}

void write_char(char c, FILE *f)
{
    fwrite((void *)(&c), sizeof(c), 1, f);
}