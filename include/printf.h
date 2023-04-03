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

    #define NB_FLAGS 6
    #define UNUSED(x) (void)x

//////////FLAGS////////////

void print_nb_char(va_list list, int *printed);
void print_number(va_list list, int *printed);
void print_float(va_list list, int *printed);
void print_char(va_list list, int *printed);
void print_str(va_list list, int *printed);

#endif //ML_PRINTF_H
