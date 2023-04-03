/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_errput.c
*/

#include "mylib.h"

void ml_putchar_err(char c)
{
    write(2, &c, 1);
}

void ml_putstr_err(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        ml_putchar_err(str[i]);
}

void ml_putnchar_err(char const *str, int len)
{
    if (len > ml_strlen(str) || len < 0)
        return;
    write(2, str, len);
}

void ml_putnbr_err(int nb)
{
    int i = 1;

    if (nb >= 0) {
        if (nb >= 10) {
            i = nb % 10;
            nb = (nb - i) / 10;
            ml_putnbr_err(nb);
            ml_putchar_err((char)(48 + i));
        } else
            ml_putchar_err((char)(48 + nb % 10));
    } else {
        ml_putchar_err('-');
        ml_putnbr_err(-nb);
    }
}
