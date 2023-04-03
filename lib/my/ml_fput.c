/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** ml_fput.c
*/

#include "mylib.h"

void ml_fputchar(char c, int fd)
{
    write(fd, &c, 1);
}

void ml_fputstr(char const *str, int fd)
{
    for (int i = 0; str[i] != '\0'; i++)
        ml_fputchar(str[i], fd);
}

void ml_fputnchar(char const *str, int len, int fd)
{
    if (len > ml_strlen(str) || len < 0)
        return;
    write(fd, str, len);
}

void ml_fputnbr(int nb, int fd)
{
    int i = 1;

    if (nb >= 0) {
        if (nb >= 10) {
            i = nb % 10;
            nb = (nb - i) / 10;
            ml_fputnbr(nb, fd);
            ml_fputchar((char)(48 + i), fd);
        } else
            ml_fputchar((char)(48 + nb % 10), fd);
    } else {
        ml_fputchar('-', fd);
        ml_fputnbr(-nb, fd);
    }
}
