/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <slavoie@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:41:38 by slavoie           #+#    #+#             */
/*   Updated: 2021/06/09 14:43:25 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	Définit les n premiers octets à 0 en commençant à s.

	args:
			s: le pointeur où commencer
			n: le nombre d'octet à mettre à 0

*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
