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

    #define NB_FLAGS 12
    #define UNUSED(x) (void)x

typedef struct info_s {
    int fd;
    bool sign;
    int printed_char;
    int precision;
}info_t;

///////////FORMATS//////////

void write_sign(char **format, info_t *info);
void change_precision(char **format, info_t *info);
void zero_padded_form(char **format, info_t *info);

//////////FLAGS////////////

void print_unsigned_int(va_list list, info_t *info);
void print_nb_char(va_list list, info_t *info);
void print_pointer(va_list list, info_t *info);
void print_percent(va_list list, info_t *info);
void print_number(va_list list, info_t *info);
void print_binary(va_list list, info_t *info);
void print_octal(va_list list, info_t *info);
void print_float(va_list list, info_t *info);
void print_char(va_list list, info_t *info);
void print_hexa(va_list list, info_t *info);
void print_str(va_list list, info_t *info);

#endif //ML_PRINTF_H
