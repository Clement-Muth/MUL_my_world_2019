/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#define KMRED "\033[1;31m"
#define KRED "\033[0;31m"
#define KMGREEN "\033[1;32m"
#define KGREEN "\033[0;32m"
#define KMYELLOW "\033[1;33m"
#define KYELLOW "\033[0;33m"
#define KMBLUE "\033[1;34m"
#define KBLUE "\033[0;34m"
#define KMMAGENTA "\033[1;35m"
#define KMAGENTA "\033[0;35m"
#define KMCYAN "\033[1;36m"
#define KCYAN "\033[0;36m"
#define KMLGRAY "\033[1;37m"
#define KLGRAY "\033[0;37m"
#define KMDGRAY "\033[1;90m"
#define KDGRAY "\033[0;90m"
#define KMLRED "\033[1;91m"
#define KLRED "\033[0;91m"
#define KMLGREEN "\033[1;92m"
#define KLGREEN "\033[0;92m"
#define KMLYELLOW "\033[1;93m"
#define KLYELLOW "\033[0;93m"
#define KMLBLUE "\033[1;94m"
#define KLBLUE "\033[0;94m"
#define KMLMANGENTA "\033[1;95m"
#define KLMANGENTA "\033[0;95m"
#define KMLCYAN "\033[1;96m"
#define KLCYAN "\033[0;96m"
#define KMWHITE "\033[1;97m"
#define KWHITE "\033[0;97m"
#define KRESET "\033[0;0m"

int my_printf(const char *restrict format, ...);

#endif /* !MY_PRINTF_H_ */