/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** my_getline
*/

#ifndef MY_GETLINE_H_
#define MY_GETLINE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct mobile_s
{
    char *send;
    int read_size;
    int not_fst_call;
    unsigned char value;
}mobile_t;

typedef struct static_s
{
    char *buf;
    int cursor;
    int inc_b;
    int fd;
    unsigned char stay;
    unsigned char _bool;
}static_t;

char *my_getline(int fd);

int if_n_or_zero_ashes(static_t *_static, char *ashes, int *inc_a);
int if_n_or_zero_letter(static_t *_static, char *link, int *inc_l);
int return_value_if_end(mobile_t *mobile, static_t *_static);
int error_fd_code(int fd, static_t *_static);

#define READ_SIZE 10
#define ERROR_FREE_BUF -73
#endif /* !MY_GETLINE_H_ */
