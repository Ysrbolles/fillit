/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 20:07:16 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/17 23:13:32 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alnumcounter(char *s)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			if (s[i++ + 1] >= '0' && s[i++ + 1] <= '9')
				j++;
			else
				i++;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if ((s[i++ + 1] >= 'a' && s[i++ + 1] <= 'z')
					|| (s[i++ + 1] >= 'A' && s[i++ + 1] <= 'Z'))
				j++;
			else
				i++;
		}
	}
	return (i + j);
}

static char	*change(char *dest, char *s, int i, int j)
{
	while (s[i] != '\0')
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			dest[j] = s[i];
			if (s[i + 1] >= '0' && s[i + 1] <= '9')
				dest[++j] = ' ';
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			dest[j] = s[i];
			if ((s[i + 1] >= 'a' && s[i + 1] <= 'z')
					|| (s[i + 1] >= 'A' && s[i + 1] <= 'Z'))
				dest[++j] = ' ';
		}
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char		*ft_alnum(char *s)
{
	char	*dest;
	int		j;
	int		i;

	if ((dest = (char*)malloc(ft_alnumcounter(s) * sizeof(char))) == NULL)
		return (NULL);
	j = 0;
	i = 0;
	return (change(dest, s, i, j));
}
