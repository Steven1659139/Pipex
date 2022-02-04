#include "libft.h"
#include <stdio.h>

int ft_str_sameStart(char *str1, char *str2)
{
    int index;

    index = 0;
    while ((str1[index] && str2[index]) && (str1[index] == str2[index]))
        index++;
    if (!str2[index])
            return (1);
    return (0);
}
