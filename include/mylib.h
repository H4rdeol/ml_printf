/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mylib.h
*/

#ifndef MYLIB_H
    #define MYLIB_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #define FAILURE 84
    #define SUCCESS 0
    #define ABS(x) (x < 0) ? (-x) : x

void ml_putnbr(int nb);
void ml_putchar(char c);
void ml_putnbr_err(int nb);
void ml_putchar_err(char c);
void ml_free_array(char **array);
void ml_fputnbr(int nb, int fd);
void ml_putstr(char const *str);
void ml_fputchar(char c, int fd);
void ml_putstr_err(char const *str);
void ml_fputstr(char const *str, int fd);
void ml_putnchar(char const *str, int len);
void ml_putnchar_err(char const *str, int len);
void ml_memset(void *data, int c, size_t size);
void ml_fputnchar(char const *str, int len, int fd);
bool ml_strcmp(char *word1, char *word2);
bool ml_strstr(char *str, char *to_find);
bool ml_strncmp(char *word1, char *word2, int n);
int ml_intlen(int nb);
int ml_atoi(char *str);
int ml_strlen(char const *str);
int ml_putnbr_base(int nbr, char const *base);
int ml_fputnbr_base(int nbr, char const *base, int fd);
char *my_itoa(int nb);
char *ml_strdup(char const *src);
char *ml_strndup(char *str, int n);
char *ml_strcpy(char *dest, char const *src);
char *ml_strcat(char *dest, char const *src);
char *ml_strncpy(char *dest, char const *src, int n);
char *ml_strncat(char *dest, char const *src, int len);
char **ml_str_to_array(char *buf);

#endif //MYLIB_H
