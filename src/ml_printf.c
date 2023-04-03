/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** ml_printf.c
*/

#include "../include/printf.h"

static void flags_func(char *format, info_t *info, va_list list)
{
    static char *flags = "difcsnpoxbu";
    void (*flags_func[NB_FLAGS])(va_list, info_t *) = {

        &print_number, &print_number, &print_float, &print_char, &print_str,
        &print_nb_char, &print_pointer, &print_octal, &print_hexa,
        &print_binary, &print_unsigned_int
    };
    for (int i = 0; i < NB_FLAGS; i++)
        if (flags[i] == format[0]) {
            flags_func[i](list, info);
            return;
        }
    if (format[0] == '%') {
        ml_fputchar('%', info->fd);
        info->printed_char++;
    } else {
        ml_putstr_err("Error flag: %");
        ml_putchar_err(format[0]);
        ml_putstr_err(": doesn't exist\n");
    }
}

static info_t get_info(char **format, va_list list)
{
    info_t info = {STDOUT_FILENO, 0, 6};

    if (!ml_strncmp(*format, ">fd", 3))
        return info;
    info.fd = (int)va_arg(list, int);
    for (int i = 0; i < 3; i++, *format = *format + 1);
    return info;
}

void ml_printf(char *format, ...)
{
    va_list list;
    info_t info;

    va_start(list, format);
    info = get_info(&format, list);
    for (; format[0]; format++) {
        if (format[0] != '%') {
            ml_fputchar(format[0], info.fd);
            info.printed_char++;
        } else
            flags_func(++format, &info, list);
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
    return SUCCESS;
}
