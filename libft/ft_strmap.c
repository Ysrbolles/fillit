/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 03:37:10 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/11 04:27:53 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	dest = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		dest[i++] = f(*s++);
	}
	dest[i] = '\0';
	return (dest);
}
