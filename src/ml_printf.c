/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** ml_printf.c
*/

#include "../include/printf.h"
#include <stdio.h>

static info_t get_info(char **format, va_list list)
{
    info_t info = {STDOUT_FILENO, false, 0, 6};

    if (!ml_strncmp(*format, ">fd", 3))
        return info;
    info.fd = (int)va_arg(list, int);
    for (int i = 0; i < 3; i++, *format = *format + 1);
    return info;
}

static int flags_func(char *format, info_t *info, va_list list)
{
    static char *flags = "difcsnpoxbu%";
    void (*flags_func[NB_FLAGS])(va_list, info_t *) = {

        &print_number, &print_number, &print_float, &print_char, &print_str,
        &print_nb_char, &print_pointer, &print_octal, &print_hexa,
        &print_binary, &print_unsigned_int, &print_percent
    };
    for (int i = 0; i < NB_FLAGS; i++)
        if (flags[i] == format[0]) {
            flags_func[i](list, info);
            return SUCCESS;
        }
    ml_putstr_err("Error flag: %");
    ml_putchar_err(format[0]);
    ml_putstr_err(": doesn't exist\n");
    return FAILURE;
}

static char *format_func(char *format, info_t *info)
{
    static char *for_flags = "0.+";
    void (*format_func[3])(char **, info_t *) = {

        &zero_padded_form, &change_precision, &write_sign
    };
    if (ml_instr(format[0], "difcsnpoxbu"))
        return format;
    for (int i = 0; i < 3; i++) {
        if (for_flags[i] == format[0]) {
            format_func[i](&format, info);
            break;
        }
    }
    return format;
}

void ml_printf(char *format, ...)
{
    va_list list;
    info_t info;
    int error = 0;

    va_start(list, format);
    info = get_info(&format, list);
    for (; format[0]; format++) {
        if (format[0] != '%') {
            ml_fputchar(format[0], info.fd);
            info.printed_char++;
        } else {
            format = format_func(++format, &info);
            error = flags_func(format, &info, list);
        }
        if (error == 84)
            break;
    }
    va_end(list);
}

int main(void)
{
    char *str = "khqdjq";

    ml_printf("coucou\n");
    ml_printf("test integer 1: %d, %i\n", 12, 23);
    ml_printf("test str and char 1: %s, %c\n", "derer", 'c');
    ml_printf("test float : %f%%, %n\n%z", 23.764f);
    ml_printf("test pointer : %p\n", str);
    ml_printf("test 0 format: %03d %n\n", 23);
    ml_printf("test precision : %.3f\n", 23.5f);
    ml_printf("test precision : %f\n", -23.05);
    ml_printf("test precision : %+f\n", 23.05);
    ml_printf("coucou %d\n", 42);
    return SUCCESS;
}
