/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:21:53 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:53:49 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		arrange(int *cord)
{
	int i;

	i = 0;
	while (i != 4)
	{
		cord[i] = cord[i] + 1;
		i++;
	}
	return (0);
}

int		is_safe(char *dest, int *cordx, int *cordy, int j)
{
	int i;

	i = 0;
	while (i != 4)
	{
		if (cordx[i] >= j || cordy[i] >= j)
			return (0);
		if (dest[cordx[i] + (j * cordy[i])] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		c_c(int j, int *cord)
{
	if (cord[0] == (j - 1))
		return (0);
	if (cord[1] == (j - 1))
		return (0);
	if (cord[2] == (j - 1))
		return (0);
	if (cord[3] == (j - 1))
		return (0);
	return (1);
}

int		ft_remove(char *dest, int *cordx, int *cordy, int j)
{
	int i;

	i = 0;
	while (i != 4)
	{
		dest[cordx[i] + (j * cordy[i])] = '.';
		i++;
	}
	return (0);
}

int		reset_cord(int *z)
{
	int i;
	int min;

	i = 0;
	min = z[0];
	while (i != 4)
	{
		if (z[i] < min)
			min = z[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		z[i] = z[i] - min;
		i++;
	}
	return (0);
}
