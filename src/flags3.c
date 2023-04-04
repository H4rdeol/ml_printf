/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** flags3.c
*/

#include "../include/printf.h"

static void write_unsigned_int(unsigned int nb, int fd)
{
    unsigned int i = 1;

    if (nb >= 10) {
        i = nb % 10;
        nb = (nb - i) / 10;
        write_unsigned_int(nb, fd);
        ml_fputchar((char)(48 + i), fd);
    } else
        ml_fputchar((char)(48 + nb % 10), fd);
}

static int len_unsignedint(unsigned int nb)
{
    unsigned int i;
    int len = 0;

    while (nb != 0){
        i = nb % 10;
        nb = (nb - i) / 10;
        len++;
    }
    return len;
}

void print_unsigned_int(va_list list, info_t *info)
{
    unsigned int nb = (unsigned int)va_arg(list, unsigned int);

    if (info->sign)
        ml_fputchar('+', info->fd);
    write_unsigned_int(nb, info->fd);
    info->printed_char += len_unsignedint(nb);
}

void print_percent(va_list list, info_t *info)
{
    UNUSED(list);
    ml_fputchar('%', info->fd);
    info->printed_char++;
}
