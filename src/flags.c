/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** flags.c
*/

#include "../include/printf.h"

void print_number(va_list list, info_t *info)
{
    int nb = (int)va_arg(list, int);

    info->printed_char += ml_intlen(nb);
    ml_fputnbr(nb, info->fd);
}

void print_char(va_list list, info_t *info)
{
    char c = (char)va_arg(list, int);

    info->printed_char += 1;
    ml_fputchar(c, info->fd);
}

void print_str(va_list list, info_t *info)
{
    char *str = (char *)va_arg(list, char *);

    info->printed_char += ml_strlen(str);
    ml_fputstr(str, info->fd);
}

void print_float(va_list list, info_t *info)
{
    double f = (double)va_arg(list, double);
    int entire_part = (int)f;
    int decimal_part;

    f -= entire_part;
    for (int i = 0; i < info->precision; i++)
        f *= 10;
    decimal_part = f;
    f -= decimal_part;
    f *= 10;
    (f >= 5) ? decimal_part += 1 : (0);
    info->printed_char += ml_intlen(decimal_part) + ml_intlen(entire_part) + 1;
    ml_fputnbr(entire_part, info->fd);
    ml_fputchar('.', info->fd);
    ml_fputnbr(decimal_part, info->fd);
}

void print_nb_char(va_list list, info_t *info)
{
    UNUSED(list);
    ml_fputnbr(info->printed_char, info->fd);
    info->printed_char += ml_intlen(info->printed_char);
}
