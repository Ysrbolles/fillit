/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:03:42 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:54:06 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		reset(int **cordx, int **cordy, int i)
{
	reset_cord(cordx[i]);
	reset_cord(cordy[i]);
	return (0);
}

t_var	put(t_var va, int **cx, int **cy, int j)
{
	int k;

	k = -1;
	while (++k != 4)
		va.dest[cx[va.i][k] + (j * cy[va.i][k])] = va.ch;
	va.ch++;
	va.i++;
	return (va);
}

t_var	recur(t_var va, int ***cx, int ***cy)
{
	int cnt;

	cnt = 0;
	while (cx[cnt])
		cnt++;
	if (va.i == 0)
	{
		reset(*cx, *cy, va.i);
		free(va.dest);
	}
	return (va);
}

t_var	res_rem(t_var va, int ***cx, int ***cy)
{
	reset(*cx, *cy, va.i);
	va.i--;
	va.ch--;
	return (va);
}
