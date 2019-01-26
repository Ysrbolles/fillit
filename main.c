/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:23:03 by ybolles           #+#    #+#             */
/*   Updated: 2019/01/26 20:52:16 by ybolles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		first_check(char *str)
{
	int	k;
	int i;
	int	l;

	i = -1;
	k = 0;
	l = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
			k++;
		if ((str[i] == '\n' && str[i - 1] != '\n') || str[i + 1] == '\0')
			l++;
		if ((str[i] == '\n' && str[i + 1] != '\n' && str[i - 1] == '\n')
				|| str[i + 1] == '\0')
		{
			if (k != 4 || l != 4)
				return (0);
			k = 0;
			l = 0;
		}
	}
	return (1);
}

int		second_check(char *str)
{
	int i;
	int k;

	k = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\n')
			return (0);
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0')
			return (0);
		if (str[i] != '\n' && str[i] != '\0')
			k++;
		if (k > 4 || (str[i] != '\n' && str[i] != '\0'
					&& str[i] != '.' && str[i] != '#'))
			return (0);
		if (str[i] == '\n')
		{
			if (k != 4 && k != 0)
				return (0);
			k = 0;
		}
	}
	return (1);
}

char	*file_checker(int fd)
{
	int		j;
	char	*str;
	char	buffer[2];

	j = 0;
	str = ft_strnew(0);
	while ((j = read(fd, buffer, 1)) > 0)
	{
		buffer[1] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	**tetri;

	if (argc != 2)
		write(1, "usage: ./fillit source_file\n", 28);
	else
	{
		fd = open(argv[1], O_RDONLY);
		str = file_checker(fd);
		if (first_check(str) == 0 || second_check(str) == 0 || !ft_strlen(str))
			write(1, "error\n", 6);
		else
		{
			tetri = separatetetri(str);
			if (checktetri(tetri) == 0)
				write(1, "error\n", 6);
			else
			{
				solving(tetri);
			}
		}
	}
	return (0);
}
