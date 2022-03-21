/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:28:54 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/21 00:29:49 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_samestr(char *str1, char *str2)
{
	int	index;

	index = 0;
	while ((str1[index] && str2[index]) && (str1[index] == str2[index]))
		index++;
	if (!str2[index] && !str1[index])
		return (1);
	return (0);
}
