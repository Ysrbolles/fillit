/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 05:07:22 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/08 16:15:22 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*dest;
	int		i;
	int		k;
	int		b;

	i = 0;
	k = 0;
	dest = (char*)str;
	while (*str)
	{
		if (*str == (char)c)
			i = k;
		str++;
		k++;
	}
	b = k - i;
	if (*str == (char)c)
		return ((char*)str);
	if (dest[i] == (char)c)
		return ((char*)str - b);
	return (NULL);
}
