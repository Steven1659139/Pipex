/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsufx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:07:59 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/21 00:10:34 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
    Ajoute l'élément "sufx" à la fin de la string passer en paramètre
*/
char	*ft_strsufx(char *sufx, char *str)
{
	char	*new_str;
	int		index;
	int		size;

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
