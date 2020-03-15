/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** pour include tout
*/

#ifndef JMY_H_
#define JMY_H_

#include <stdio.h>

void my_putchar(char c);
void my_swapi(int *a, int *b);
void my_swapo(float *a, float *b);
void my_revstr(char *str);
////////////////////////////////////////////////////////////
///
/// \brief free management
///
/// \param one = 1 (str maybe to free)
/// \param two = 3 (str maybe to free)
/// \param three = 5 (str maybe to free)
/// \param delete have to add the number
/// to choose which one to free
///
///
///
////////////////////////////////////////////////////////////
void my_free(char *one, char *two, char *three, int delete);

/////////////////////////////////////////////////////////
///
/// \brief put str with color
///
/// \param str string you want to display
/// \param color choose witch color
/// \param option different options
/// \param delete free or not free
/////////////////////////////////////////////////////////
void my_putbase(int nb, char *base, int len_base);
int my_intlen(int nb);
int my_occur(char *str, char element);
int my_put_nbr(int nb);
int my_is_num(char *str);

int my_putstr(char const *str);
int nl_putstr(char *str);
void my_putrstr(char *str, int release);
void my_putcstr(char *str, char *color, int option, int release);

int my_strlen(char const *str);
int my_length_lim(char *str, char lim, int release);
int my_length_lim_nb(char *str, char lim, int occurence, int release);
int my_length_st(char *str, char start, int release);

int my_atoi(char const *str);
int nl_atoi(char *str);

int my_strcmp(char *s1, char *s2, int release);
int my_strcmp_low(char *s1, char *s2, int release);

int my_isalpha_num(char *str);
int my_isin(char *str, char open, char close, int release);
int my_isnum(char character);
int my_isalpha(char character, char open, char close);

char *my_ch_base(int nb, char *base);

char *my_intchar(int nb);

char *my_cpy(char *src, int release);
char *my_cpy_st(char *str, char start, int release);
char *my_cpy_lim(char *original, char lim, int release);

char *my_strcat(char *one, char *two, int release);
char *my_strcat_in(char *bread, char *sausage, char ketchup, int release);
char *my_strcat_bside(char *one, char *two, char *three, int release);

char **my_malloc_db(int height, int width);
int **my_malloc_db_int(int height, int width);
void **my_malloc_type(int height, int width, int size_db, int size);

typedef struct clean_s
{
    int i;
    int e;
    int block;
    char one;
    char two;
}clean_t;

void my_cleanstr(char *str, char one, char two);
void my_clean(char *str, char one, char two);
#endif