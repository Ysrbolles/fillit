/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:33:56 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:54:35 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		setcord(int *z)
{
	int i;
	int min;

	i = 0;
	min = 3;
	while (z[i])
	{
		if (z[i] < min)
		{
			min = z[i];
		}
		i++;
	}
	i = 0;
	while (z[i])
	{
		z[i] = z[i] - min;
		i++;
	}
	return (0);
}

int		**alloc_cord(int **cord, int count)
{
	int i;

	i = 0;
	if ((cord = malloc(sizeof(int *) * (count + 1))) == NULL)
		return (0);
	cord[count + 1] = NULL;
	while (i != (count + 1))
	{
		if ((cord[i] = malloc(sizeof(int) * 4)) == NULL)
			return (0);
		i++;
	}
	return (cord);
}

int		check_to_setup(int i, int **cordx, int **cordy)
{
	if (cordx[i][0] != 0 && cordx[i][1] != 0
			&& cordx[i][2] != 0 && cordx[i][3] != 0)
		setcord(cordx[i]);
	if (cordy[i][0] != 0 && cordy[i][1] != 0
			&& cordy[i][2] != 0 && cordy[i][3] != 0)
		setcord(cordy[i]);
	return (0);
}

int		cord(char **str, int count, int i)
{
	int j;
	int	k;
	int	**cordx;
	int	**cordy;

	cordx = NULL;
	cordy = NULL;
	cordx = alloc_cord(cordx, count);
	cordy = alloc_cord(cordy, count);
	while (str[++i])
	{
		j = -1;
		k = 0;
		while (str[i][++j] != '\0')
			if (str[i][j] == '#')
			{
				cordx[i][k] = (j % 4);
				cordy[i][k++] = (j / 4);
			}
		check_to_setup(i, cordx, cordy);
	}
	j = 2;
	place(cordx, cordy, count, j);
	return (0);
}

char	**solving(char **str)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (str[count])
		count++;
	cord(str, count, i);
	return (0);
}
