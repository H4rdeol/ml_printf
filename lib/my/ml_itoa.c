/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_itoa.c
*/

#include "mylib.h"

int ml_intlen(int nb)
{
    int i;
    int len = 0;

    if (nb < 0){
        len += 1;
        nb = nb * -1;
    }
    while (nb != 0){
        i = nb % 10;
        nb = (nb - i) / 10;
        len ++;
    }
    return len;
}

char *my_itoa(int nb)
{
    int len = ml_intlen(nb);
    char *str = malloc(sizeof(char) * len + 1);

    if (nb == 0) {
        str = "0\0";
        return str;
    }
    for (int i = 0; i < len; i++){
        str[len - (i + 1)] = (char)(48 + (nb % 10));
        nb /= 10;
    }
    str[len] = '\0';
    return str;
}
