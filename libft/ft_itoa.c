/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 21:27:30 by nhamid            #+#    #+#             */
/*   Updated: 2018/10/18 06:21:59 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countnb(int n)
{
	unsigned int i;
	unsigned int nb;

	i = 0;
	if (n < 0)
	{
		nb = n * -1;
		i++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static char	*hhh(char *str, unsigned int i, unsigned int k)
{
	str = (char*)malloc(sizeof(char) * i + 2);
	str[i] = 48;
	str[++k] = '\0';
	return (str);
}

char		*ft_itoa(int c)
{
	unsigned int	i;
	unsigned int	nb;
	unsigned int	k;
	char			*str;

	i = countnb(c);
	k = i;
	if ((str = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	if (c == 0)
	{
		str = hhh(str, i, k);
		return (str);
	}
	nb = (c < 0) ? (c * -1) : c;
	if (c < 0)
		str[0] = '-';
	str[i] = '\0';
	i--;
	while (nb != 0)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
