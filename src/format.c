/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** format.c
*/

#include "../include/printf.h"

void zero_padded_form(char **format, info_t *info)
{
    int nb_zero = ml_atoi(*format);

    if (nb_zero == 0 && !ml_isint(*format[1])) {
        ml_putstr_err("ERROR: bad usage of 0 format ");
        ml_putstr_err("you need to write an integer after 0.\n");
        ml_putstr_err("Format doesn't applied write normally.\n");
        *format = *format + 1;
        return;
    }
    for (int i = 0; i < nb_zero; i++) {
        ml_fputchar('0', info->fd);
        info->printed_char++;
    }
    for (int i = 0; i < ml_intlen(nb_zero) + 1; i++)
        *format = *format + 1;
}

void change_precision(char **format, info_t *info)
{
    int precision = 6;

    *format = *format + 1;
    precision = ml_atoi(*format);
    if (precision == 0) {
        ml_putstr_err("ERROR: Precision can't be inferior or equal to 0\n");
        ml_putstr_err("Precision not changed\n");
        return;
    }
    info->precision = precision;
    for (int i = 0; i < ml_intlen(precision); i++)
        *format = *format + 1;
}

void write_sign(char **format, info_t *info)
{
    *format = *format + 1;
    info->sign = true;
}
