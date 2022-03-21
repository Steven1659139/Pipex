/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_samestart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:12:18 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/21 00:13:34 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_samestart(char *str1, char *str2)
{
	int	index;

	index = 0;
	while ((str1[index] && str2[index]) && (str1[index] == str2[index]))
		index++;
	if (!str2[index])
		return (1);
	return (0);
}
