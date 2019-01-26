/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:50:57 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:51:02 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**checktetri(char **str)
{
	int i;
	int j;
	int count;

	i = -1;
	while (str[++i])
	{
		j = 0;
		count = 0;
		while (str[i][j])
		{
			if ((j == 3 || j == 7 || j == 11)
					&& str[i][j] == '#' && str[i][j + 1] == '#')
				count--;
			if (str[i][j] == '#' && str[i][j + 1] == '#')
				count++;
			if (str[i][j] == '#' && str[i][j + 4] == '#')
				count++;
			j++;
		}
		if (count != 3)
			if (count != 4)
				return (0);
	}
	return (str);
}
