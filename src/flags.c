/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** flags.c
*/

#include "../include/printf.h"

void print_number(va_list list, int *print)
{
    int nb = (int)va_arg(list, int);

    *print += ml_intlen(nb);
    ml_putnbr(nb);
}

void print_char(va_list list, int *print)
{
    char c = (char)va_arg(list, int);

    *print += 1;
    ml_putchar(c);
}

void print_str(va_list list, int *print)
{
    char *str = (char *)va_arg(list, char *);

    *print += ml_strlen(str);
    ml_putstr(str);
}

void print_float(va_list list, int *printed)
{
    double f = (double)va_arg(list, double);
    int entire_part = (int)f;
    int decimal_part = 0;

    f -= entire_part;
    for (int i = 0; i < 6; i++)
        f *= 10;
    decimal_part = f;
    f -= decimal_part;
    f *= 10;
    (f >= 5) ? decimal_part += 1 : (0);
    *printed += ml_intlen(decimal_part) + ml_intlen(entire_part) + 1;
    ml_putnbr(entire_part);
    ml_putchar('.');
    ml_putnbr(decimal_part);
}

void print_nb_char(va_list list, int *printed)
{
    UNUSED(list);
    ml_putnbr(*printed);
    *printed += ml_intlen(*printed);
}
