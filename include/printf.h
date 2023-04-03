/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** printf.h
*/
#ifndef ML_PRINTF_H
    #define ML_PRINTF_H

    #include <stdarg.h>
    #include "mylib.h"

    #define NB_FLAGS 11
    #define UNUSED(x) (void)x

typedef struct info_s {
    int fd;
    int printed_char;
    int precision;
}info_t;

//////////FLAGS////////////

void print_unsigned_int(va_list list, info_t *info);
void print_nb_char(va_list list, info_t *info);
void print_pointer(va_list list, info_t *info);
void print_number(va_list list, info_t *info);
void print_binary(va_list list, info_t *info);
void print_octal(va_list list, info_t *info);
void print_float(va_list list, info_t *info);
void print_char(va_list list, info_t *info);
void print_hexa(va_list list, info_t *info);
void print_str(va_list list, info_t *info);

#endif //ML_PRINTF_H
