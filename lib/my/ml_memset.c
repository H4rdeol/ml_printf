/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_memset.c
*/

#include "mylib.h"

void ml_memset(void *data, int c, size_t size)
{
    unsigned char *s = data;

    for (size_t i = 0; i < size; i++)
        *(s + i) = (unsigned char) c;
}
