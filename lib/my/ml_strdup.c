/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_strdup.c
*/

#include "mylib.h"

char *ml_strdup(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * ml_strlen(src) + 1);

    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *ml_strndup(char *str, int n)
{
    char *res = malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; i++)
        res[i] = '\0';
    for (int i = 0; i < n && str[i] != '\0'; i++)
        res[i] = str[i];
    res[n] = '\0';
    return res;
}
