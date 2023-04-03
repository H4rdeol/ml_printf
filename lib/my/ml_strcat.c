/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_strcat.c
*/

char *ml_strcat(char *dest, char const *src)
{
    int index = 0;
    int ind_src = 0;

    for (;dest[index]; index++);
    for (;src[ind_src]; ind_src++)
        dest[index++] = src[ind_src];
    dest[index] = '\0';
    return dest;
}

char *ml_strncat(char *dest, char const *src, int len)
{
    int index = 0;
    int ind_src = 0;

    for (;dest[index]; index++);
    for (;ind_src < len && src[ind_src]; ind_src++)
        dest[index++] = src[ind_src];
    dest[index] = '\0';
    return dest;
}
