/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** flags2.c
*/

#include "../include/printf.h"

static int write_hexa_ptr(unsigned long nbr, char const *base, int fd)
{
    int i = 0;
    int len = ml_strlen(base);
    int count = 0;

    if (nbr >= len){
        i = nbr % len;
        nbr = (nbr - i) / len;
        count++;
        write_hexa_ptr(nbr, base, fd);
        ml_fputchar(base[i], fd);
    }else{
        count++;
        ml_fputchar(base[nbr], fd);
    }
    return count;
}

void print_pointer(va_list list, info_t *info)
{
    unsigned long ptr = (unsigned long)va_arg(list, unsigned long);

    ml_fputstr("0x", info->fd);
    info->printed_char += write_hexa_ptr(ptr, "0123456789abcdef", info->fd);
}

void print_binary(va_list list, info_t *info)
{
    int nb = (int)va_arg(list, int);

    info->printed_char += ml_fputnbr_base(nb, "01", info->fd);
}

void print_octal(va_list list, info_t *info)
{
    int nb = (int)va_arg(list, int);

    info->printed_char += ml_fputnbr_base(nb, "01234567", info->fd);
}

void print_hexa(va_list list, info_t *info)
{
    int nb = (int)va_arg(list, int);

    info->printed_char += ml_fputnbr_base(nb, "0123456789abcdef", info->fd);
}
