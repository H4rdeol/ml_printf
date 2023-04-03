/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** ml_atoi.c
*/

int ml_atoi(char *str)
{
    int nb = 0;
    int isneg = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-'){
        if (str[i] == '-')
            isneg = isneg * -1;
        i++;
    }
    while (str[i] != '\0'){
        if (str[i] >= '0' && str[i] <= '9'){
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        } else
            break;
    }
    return (nb * isneg);
}
