/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:28:48 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:52:45 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*allocnumber(int i)
{
	int		k;
	int		l;
	char	*str;

	l = i * i;
	k = 0;
	if ((str = malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	while (k < l)
	{
		str[k] = '.';
		k++;
	}
	str[k] = '\0';
	return (str);
}

void	display_result(char *dest, int j)
{
	int i;
	int l;

	i = 0;
	l = 1;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		if (l == j)
		{
			write(1, "\n", 1);
			l++;
			l = 1;
		}
		else
			l++;
		i++;
	}
}

int		arrange_function(int **cordx, int **cordy, int i, int j)
{
	if (c_c(j, cordx[i]) == 0)
	{
		reset_cord(cordx[i]);
		arrange(cordy[i]);
	}
	else
		arrange(cordx[i]);
	return (0);
}

int		place(int **cx, int **cy, int cnt, int j)
{
	t_var		v;

	v.ch = 'A';
	v.i = 0;
	v.dest = allocnumber(j);
	while (v.i != cnt)
	{
		if (is_safe(v.dest, cx[v.i], cy[v.i], j) == 0)
			while (is_safe(v.dest, cx[v.i], cy[v.i], j) == 0)
			{
				if ((c_c(j, cx[v.i]) == 0 && c_c(j, cy[v.i]) == 0))
					while (c_c(j, cx[v.i]) == 0 && c_c(j, cy[v.i]) == 0)
					{
						v = recur(v, &cx, &cy);
						if (v.i == 0 && !(place(cx, cy, cnt, j + 1)))
							return (0);
						v = res_rem(v, &cx, &cy);
						ft_remove(v.dest, cx[v.i], cy[v.i], j);
					}
				arrange_function(cx, cy, v.i, j);
			}
		v = is_safe(v.dest, cx[v.i], cy[v.i], j) != 0 ? put(v, cx, cy, j) : v;
	}
	display_result(v.dest, j);
	return (0);
}
