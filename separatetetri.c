/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separatetetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:47:11 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:53:18 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**copy(char *str, char **dest)
{
	int		j;
	int		l;
	int		k;

	j = 0;
	l = 0;
	k = 0;
	while (str[j] != '\0')
	{
		if (str[j] != '\n')
			dest[l][k++] = str[j];
		if (k == 16)
			l++;
		k = (k == 16) ? 0 : k;
		j++;
	}
	dest[l] = NULL;
	return (dest);
}

char	**separatetetri(char *str)
{
	int		l;
	int		i;
	char	**tetri;

	l = 0;
	i = 0;
	while (str[l] != '\0')
	{
		if (str[l] == '\n' && (str[l + 1] == '\n' || str[l + 1] == '\0'))
			i++;
		l++;
	}
	l = 0;
	if (((tetri = malloc(sizeof(char*) * (i + 1))) == NULL))
		return (NULL);
	while (l != i)
	{
		if ((tetri[l] = malloc(sizeof(char) * 17)) == NULL)
			return (NULL);
		tetri[l++][16] = '\0';
	}
	tetri = copy(str, tetri);
	return (tetri);
}
