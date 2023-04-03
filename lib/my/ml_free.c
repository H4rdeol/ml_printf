/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** free_array.c
*/

#include "mylib.h"

void ml_free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
