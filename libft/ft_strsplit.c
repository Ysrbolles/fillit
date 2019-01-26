/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 05:06:40 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/19 01:36:04 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		w(char const *str, char c)
{
	int i;
	int k;

	i = 0;
	k = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			k++;
			if (str[i - 1] == c)
			{
				if (str[i + 1] == '\0')
					k--;
				k--;
			}
		}
		i++;
	}
	if (str[0] == c)
		k--;
	return (k);
}

static int		charcount(char const *str, int i, char c)
{
	int count;

	count = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			break ;
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**st;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((s == NULL) || ((st = malloc(sizeof(char*) * (w(s, c) + 1))) == NULL))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			if ((st[j] = malloc(sizeof(char) * charcount(s, i, c))) == NULL)
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				st[j][k++] = s[i++];
			st[j++][k] = '\0';
		}
		else
			i++;
	}
	st[j] = NULL;
	return (st);
}
