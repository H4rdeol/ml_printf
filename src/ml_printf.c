/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** ml_printf.c
*/

#include "../include/printf.h"
#include <stdio.h>

static int flags_func(char *format, int printed, va_list list)
{
    static char *flags = "difcsn";
    void (*flags_func[NB_FLAGS])(va_list, int *) = {

        &print_number, &print_number, &print_float, &print_char, &print_str,
        &print_nb_char
    };
    for (int i = 0; i < NB_FLAGS; i++) {
        if (flags[i] == format[0]) {
            flags_func[i](list, &printed);
            return printed;
        }
    }
    if (format[0] == '%') {
        ml_putchar('%');
    } else {
        ml_putstr_err("Error flags: %");
        ml_putchar_err(format[0]);
        ml_putstr_err(": doesn't exist\n");
    } return printed;
}

void ml_printf(char *format, ...)
{
    int print_char = 0;
    va_list list;

    va_start(list, format);
    for (; format[0]; format++) {
        if (format[0] != '%') {
            ml_putchar(format[0]);
            print_char++;
        } else
            print_char = flags_func(++format, print_char, list);
    }
}

int main(void)
{
    ml_printf("coucou\n");
    ml_printf("test integer 1: %d, %i\n", 12, 23);
    ml_printf("test str and char 1: %s, %c\n", "derer", 'c');
    ml_printf("test float : %f%%, %n\n%z", 23.764f);
    return SUCCESS;
}
