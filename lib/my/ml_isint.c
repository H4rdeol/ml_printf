/*
** EPITECH PROJECT, 2023
** ml_printf
** File description:
** ml_isint.c
*/

#include "mylib.h"

bool ml_isint(char c)
{
    if (c < 48 || c > 57)
        return false;
    return true;
}

bool ml_strisnumber(char *str)
{
    for (int i = 0; i < ml_strlen(str); i++)
        if (str[i] < 48 || str[i] > 57)
            return false;
    return true;
}
