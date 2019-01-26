/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:15:11 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/18 07:59:35 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*src;
	size_t		i;

	i = 0;
	src = str;
	while (i < n)
	{
		if (src[i] == (char)c)
			return ((void *)src + i);
		i++;
	}
	return (NULL);
}
