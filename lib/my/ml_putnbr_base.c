/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** ml_putnbr_base.c
*/

#include "mylib.h"

int ml_putnbr_base(int nbr, char const *base)
{
    int i;
    int count = 0;
    int len = ml_strlen(base);

    if (nbr >= 0){
        if (nbr >= len){
            i = nbr % len;
            nbr = (nbr - i) / len;
            count++;
            ml_putnbr_base(nbr, base);
            ml_putchar(base[i]);
        }else{
            count++;
            ml_putchar(base[nbr]);
        }
    }else{
        ml_putchar('-');
        count++;
        ml_putnbr_base(nbr * -1, base);
    } return count;
}

int ml_fputnbr_base(int nbr, char const *base, int fd)
{
    int i;
    int count = 0;
    int len = ml_strlen(base);

    if (nbr >= 0){
        if (nbr >= len){
            i = nbr % len;
            nbr = (nbr - i) / len;
            count++;
            ml_fputnbr_base(nbr, base, fd);
            ml_fputchar(base[i], fd);
        }else{
            count++;
            ml_fputchar(base[nbr], fd);
        }
    }else{
        ml_fputchar('-', fd);
        count++;
        ml_fputnbr_base(nbr * -1, base, fd);
    } return count;
}
