/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** main
*/

#include "my_world.h"

int main(int argc, char **argv)
{
    if (argc != 5)
        return (84);
    return (world_loop(argc, argv));
}