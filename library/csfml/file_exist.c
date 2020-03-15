/*
** EPITECH PROJECT, 2020
** re
** File description:
** file_exist
*/

#include "csfml.h"

static sfBool
strcomp(const char *compared, const char *comparing)
{
    int i = 0;

    for (; compared[i] == comparing[i] && compared[i]; ++i);
    return (compared[i] == 0 && compared[i] == comparing[i]) ? (sfTrue) :
    (sfFalse);
}

int
file_exist(char *filename)
{
    int n = 0;
    DIR *dir = opendir("save/");
    struct dirent *d;

    if (!dir) return (-1);
    while ((d = readdir(dir))) {
        if (strcomp(d->d_name, my_strcat(filename, ".legend", 0))) {
            n = 1;
            break;
        }
    }
    closedir(dir);
    return (n == 1) ? (sfTrue) : (sfFalse);
}