/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_strstr.c
*/

#include "mylib.h"

bool ml_strstr(char *str, char *to_find)
{
    int k = 0;
    int i = 0;
    int len = ml_strlen(str);

    for (; i < len; i++){
        if (str[i] == to_find[k]){
            k++;
        }else {
            k = 0;
        }
        if (k == ml_strlen(to_find))
            break;
    }
    if (k == ml_strlen(to_find))
        return true;
    return false;
}
