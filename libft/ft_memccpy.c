/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:19:55 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/17 22:11:35 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;
	char	*src;
	char	*dst;
	char	k;

	dst = (char*)s1;
	src = (char*)s2;
	k = c;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == k)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
