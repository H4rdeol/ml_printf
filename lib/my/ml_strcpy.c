/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_strcpy.c
*/

char *ml_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest[0] = '\0';
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *ml_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    dest[0] = '\0';
    while (src[i] != '\0' && i < n){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
