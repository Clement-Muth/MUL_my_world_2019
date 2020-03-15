/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** array
*/

#ifndef ARRAY_H_
#define ARRAY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct oootoo_s
{
    int e;
    int i;
}oootoo_t;

typedef struct otoo_s
{
    int e;
    int o;
    int i;
    int nb_part;
    int *space;
    char **otoo;
}otoo_t;

void my_putc(char c);
void my_puto(char *o);
void my_putoo(char **oo);
void my_putooo(char ***ooo, char r_one, char r_two);

void my_free_oo(char **oo);
void my_free_typoo(void **oo);
void my_free_ooo(char ***ooo);

int my_length_o(char *o);
int my_length_oo(char **oo);
int my_length_ooo(char ***ooo);

char **my_add_o_too(char **oo, char *o);
char ***my_add_oo_tooo(char ***ooo, char **oo);

char **my_otoo(char *str, char sep_one, char sep_two, int *nb_of_part);
char *my_ooto(char **oo, char sep_one, char sep_two);
char **my_oootoo(char ***ooo, char relate_one);
char ***my_ootooo(char **oo, char sep_one, char sep_two);

char **my_rm_o_too(char **oo, char *o);

char *my_cpy_o(char *o);
char **my_cpy_oo(char **oo);

int my_count_co(char *str, char character);
int my_count_coo(char **str, char character);
int my_count_too(char **str, char open, char close);

#endif /* !ARRAY_H_ */
