#include "libft.h"

char *ft_strsufx(char *sufx, char *str)
{
    char *new_str;
    int index;
    int size;

    index = -1;
    size = ft_strlen(sufx) + ft_strlen(str) + 1;
    new_str = malloc(sizeof(char) * size);
    if (!new_str)
        return (0);
    while (str[index++])
            new_str[index] = str[index];
    while (*sufx)
    {
        new_str[index] = *sufx;
        index++;
        sufx++;
    }
    new_str[index] = '\0';
    return (new_str);
}
