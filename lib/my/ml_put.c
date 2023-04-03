/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_putnbr.c
*/

#include "mylib.h"

void ml_putchar(char c)
{
    write(1, &c, 1);
}

void ml_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        ml_putchar(str[i]);
}

void ml_putnchar(char const *str, int len)
{
    if (len > ml_strlen(str) || len < 0)
        return;
    write(1, str, len);
}

void ml_putnbr(int nb)
{
    int i = 1;

    if (nb >= 0) {
        if (nb >= 10) {
            i = nb % 10;
            nb = (nb - i) / 10;
            ml_putnbr(nb);
            ml_putchar((char)(48 + i));
        } else
            ml_putchar((char)(48 + nb % 10));
    } else {
        ml_putchar('-');
        ml_putnbr(-nb);
    }
}
