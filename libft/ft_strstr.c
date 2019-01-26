/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:50:35 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/18 06:20:17 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *find, const char *tofind)
{
	int i;
	int j;

	i = 0;
	if (tofind[0] == '\0')
		return ((char*)find);
	while (find[i] != '\0')
	{
		j = 0;
		while (tofind[j] != '\0')
		{
			if (find[i + j] != tofind[j])
				break ;
			j++;
		}
		if (tofind[j] == '\0')
			return ((char*)(find + i));
		i++;
	}
	return (0);
}
