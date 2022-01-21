#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (index);
	while ((*s1 && *s2) && (index < n))
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		index++;
	}
	if (index == n)
	{
		s1--;
		s2--;
	}	
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
