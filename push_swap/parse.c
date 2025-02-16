#include "pushswap.h"

void free_split(char **s)
{
    int i;

    i = 0;
    while(s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}

void check_digit(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (ft_isdigit(s[i]) || s[i] == ' ' || ((s[i] == '+' || s[i] == '-' ) && s[i + 1] && ft_isdigit(s[i + 1]) && (i == 0 || s[i - 1] == ' ')))
            i++;
        else
        {
            ft_putstr_fd("Error", 1);
            free(s);
            exit(1);
        }
    }
}

void check_overflow(char *s)
{
    if (ft_strlen(s) > 11)
    {
        ft_putendl_fd("Error", 1);
        exit(1);
    }
    else if (ft_atol(s) > INT_MAX || ft_atol(s) < INT_MIN)
    {
        ft_putendl_fd("Error", 1);
        exit(1);
    }
}
//checkear caracteres alfanumericos (valen los signo negativos y positivos?) y si hay overflow
//Cuidado con dejar pasar signos en medio de numeros!
void check(char *full_result)
{
    char **split;
    int var;
    int i;
    int j;

    i = 0;
    check_digit(full_result);
    split = ft_split(full_result, ' ');
    while (split[i] && split[i + 1])
    {
        j = i + 1;
        check_overflow(split[i]);
        var = ft_atol(split[i]);
        while(split[i] && split[j])
        {
            check_overflow(split[j]);
            if (var == ft_atol(split[j]))
            {
                free_split(split);
                ft_putstr_fd("Not valid input", 1);
                exit (1);
            }
            j++;
        }
        i++;
    }
    free_split(split);
}

char *join_and_check(char *argv[], int argc)
{
    char *join_space;
    char *full_result;
    char *aux_result;
    int i;

    full_result = ft_strjoin(argv[1], " ");
    i = 2;
    while(i <= argc - 1)
    {
        join_space = ft_strjoin(argv[i], " ");
        aux_result = full_result;
        full_result = ft_strjoin(aux_result, join_space);
        free(aux_result);
        free(join_space);
        i++;
    }
    i = 0;
    check(full_result);
    return(full_result);
}
